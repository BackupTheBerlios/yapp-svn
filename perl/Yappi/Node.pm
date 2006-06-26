package Node ;
use strict ;
use threads;
use threads::shared;
use Yappi::NodeCore ;
use Yappi::Subscription; 
###############################################################################################################################

my $MIN_SERVERS=1;
my $cserverlist : shared ;
my $clientid : shared ;
sub new {
    my ($class, %args) = @_;
    my $id = $args{ id } ;

    my $self = {
	subscriptions => {} 
	} ;

    $cserverlist =  &share([]);

    bless $self, $class;
    return $self ;
}

sub dummy {
    
    while(1){ print "Hola\n" ; sleep 2; }

}


sub start {

    my $self = shift ;
    
    my $thr = new threads \&listener, $self ;
    $thr->detach;

    my $sthr = new threads \&slistener, $self ;
    $thr->detach;

    my $sthr = new threads \&stats, $self ;
    $thr->detach;
    return ;
}

###############################################################################################################################
sub updateCallback {
    my $self = shift ;
    my $callback = shift ;
    $self -> {updateCallback} = $callback  ;
    
    return ;
}
###############################################################################################################################
sub statusCallback {
    my $self = shift ;
    my $callback = shift ;
    $self -> {statusCallback} = $callback  ;
    return ;
}
###############################################################################################################################
sub subscribe {
    my $self = shift ;
    my $yec = shift ;
    my $subscription = Subscription->new('yec' => $yec) ;
    $self->{'subscriptions'}->{$yec} = $subscription ;
    printf "Node::subscribe: Subscribed to %s \n" , $subscription->{yec} ;

    return $subscription;
}
###############################################################################################################################
sub subscriptions {
	my $self = shift ;
	my $yec = shift ;
	#print "Return subscription for $yec\n" ;
	
	if ( $yec ) {
	    return $self->{'subscriptions'}->{$yec} ;
	} else {
	    return $self->{'subscriptions'} ;
	}
}
###############################################################################################################################

sub sendUpdate  {
	my $self = shift ;
	my $tick = shift ;
	push @{$self->{ticks}} , $tick ;
	printf "Notifying all peers new tick for yec: %s\n", $tick->{'entity'}->{'yec'} ;	
	foreach ( $self -> {'peers' } ) {

	}
	return  ;
}

sub storeTick {

    my $self = shift ;
    my $tick = shift ;
    my $yec = shift ;
    printf "Node::storeTick Called %s, %s \n" , $tick->{time}, $yec ;
    push @{$self->subscriptions($yec)->{ticks}} , $tick ;
    my @ticks;
    @ticks = $self->history($yec) ;
    #@ticks = @{$self->subscriptions($yec)->{ticks}} ;
    printf "Node::storeTick I have now %s ticks\n" , $#ticks ;
    return 1 ;
}

sub history {

    my $self = shift ;
    my $yec = shift ;
    printf "Node::history Called for %s\n" , $yec ;
    my @ticks = @{$self->subscriptions($yec)->{ticks}} ;
    printf "Node::history return %s ticks\n" , $#ticks ;
    return @ticks ;

}



sub newData {

    my $self = shift ;
    my $tick = shift ;
    $self->storeTick ($tick, $tick->{yec} ) ;
    my $cb = $self -> {updateCallback} ;
    &{$cb}($tick) ;
    return ;
}

sub listenerfake {
    while (1) {
	sleep 1 ;
	print "Fake Thread\n" ;
    }

}

# Contacts snodes and listens
# for control messages in the network
sub listener {

    my $self = shift ;

    my @serverlist = NodeCore::getServerList() ;

    my $readServer_set = new IO::Select();

    if ( $#serverlist < 0 ) {
	warn "Couldnt find a list of servers\n" ;
	return ;
    }

    print "Found $#serverlist+1 nodes to connect to\n" ;
    
    while (1) {

	# Try servers in the list until we reach $MIN_SERVERS
	# of course if serverlist is smaller than $MIN_SERVERS
	# then serverlist size applies
	while ( $readServer_set->count() < $MIN_SERVERS && 
		$readServer_set->count() < $#serverlist ) {
	    for ( @serverlist) {
		printf "Connecting to %s:%s\n" , $_->{'servername'},$_->{'port'} ;

		my ($s, $tmpid) = NodeCore::connectToServer($_, $clientid) ;

		# create handle set for reading
		if ( $s ) {
		    $clientid = $tmpid ;
		    print "Node::listener Connected and happy with an id $clientid\n" ;
		    $readServer_set->add($s);
		    print "Node::listener adding new server to the list of connected servers\n" ;
		    push @{$cserverlist} , $_->{'servername'} . ":" . $_->{'port'} ;
		    # add the main socket to the set
		}
	    }
	    warn "We are not connected to a server, wait and retry\n" ;
	    sleep(10) ;
	}
	
	#my $rh_set = IO::Select->select($readServer_set, undef, undef, 0);
	while (my @ready = $readServer_set->can_read ) { # forever
	    
	    # take all readable handles in turn
	    
	    foreach my $rh (@ready) {
		
		my $buf = <$rh>;
		if($buf) { # we get normal input
		    # ... process $buf ...
		    print "Server says $buf\n" ;
		}
		else { # the client has closed the socket
		    # remove the socket from the $read_set and close it
		    $readServer_set->remove($rh);
		    close($rh);
		}
		
	    } # foreach $rh
	    
	} # While ready sockets
    } # infinite loop    

    warn "Node::listener ENDS!!!!\n" ;
    return ;
    # simulate some real traffic ...
    my $myEntity = Entity -> new( yec => "WEA.MADRID" ) ;

    while (1) {
	sleep 1;
	my $newtick = $myEntity->createTick ( temperature => 25,
					  humidity => 40) ;    

	$self->newData($newtick) ;
	
	sleep 5 ;
	$newtick = $myEntity->createTick ( temperature => 26,
					   humidity => 39  ) ;    
	$self->newData($newtick) ;
	
	sleep 5 ;
	$newtick = $myEntity->createTick ( temperature => 27,
					   humidity => 37  ) ;    
	$self->newData($newtick) ;
    }
    

}

# This is teh server listener ...
# Waits for connections from :
# - Nodes in the network
# - SuperNodes
sub slistener {

    my $ss = NodeCore::snodeListenSocket() ;
    my ($ns, $buf);
    my $readNode_set = new IO::Select($ss);
    printf "Node::slistener wait for connections\n" ;
    
    while(my @ready = $readNode_set->can_read) {
	foreach my $rh (@ready) {
	    if($rh == $ss) {
		# Create a new socket
		my $new = $ss->accept;
		$readNode_set->add($new);
		my $peeraddr = Socket::inet_ntoa($new->peeraddr() );
		printf "Node::slistener Someone has connected from %s\n", $peeraddr ;

	    }
	    else {
		# Process socket
		$buf = <$rh>;
		if($buf) { # we get normal input
		    # ... process $buf ...		    
		    print "Node::slistener It says $buf\n" ;
		    if ( $buf =~ /GET\ \/HELO/ ) {
			print "Lets reply with an RHELO ...";
			print $rh "RHELO\n" ;

			# Check if this has a client id already
			# if not provide one

			if ( $buf =~ /HELO\ (.+)/ ) {
			    print $rh "CLID $1\n" ;			    

			} else {

			    print $rh "CLID 123123123\n" ;
			}
		    }
		}
		else { # the client has closed the socket
		    # remove the socket from the $read_set and close it
		    print "Node::slistener closes connection\n" ;
		    $readNode_set->remove($rh);
		    close($rh);
		}

	    }
	}
    }
    
}    

sub stats {


    while(1) {
	my @cserverlist = @{$cserverlist} ;
	print "We are clientid $clientid connected to : $#cserverlist + 1 servers\n" ;
	for (@cserverlist) { print "Server: $_\n" ;} 
	sleep(10) ;
    }

}

1 ;

