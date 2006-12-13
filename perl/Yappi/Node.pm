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
my @peers ;
share(@peers) ;
sub new {
    my ($class, %args) = @_;
    my $id = $args{ id } ;

    my $self = {
	subscriptions => {},
	serverlist => [],
	sport => "5555",
	serverListUrl => '',
	serverEnabled => 1
	    
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
    
    my $thr = new threads \&clistener, $self ;
    $thr->detach;

    if ( $self -> {serverEnabled} ) {
	print "Node::start() Start slistener\n" ;
	my $sthr = new threads \&slistener, $self ;
	$thr->detach;
    }

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
####################################################################
sub setIncomingPort {
    my $self = shift ;
    my $port = shift ;
    $self -> {sport} = $port  ;
    return ;
}
####################################################################
sub statusCallback {
    my $self = shift ;
    my $callback = shift ;
    $self -> {statusCallback} = $callback  ;
    return ;
}
####################################################################
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
	my $yec = $tick->{'entity'}->{'yec'} ;
	printf "Notifying all peers new tick for yec: %s\n", $yec;

	#foreach my $peer ( @{$self -> {'peers' }} ) {
	foreach my $peer ( @peers ) {
	    # We should check if they subscribed to this
	    # yec
	    printf "Does peer %s want it?\n" , $peer  ;
	    #if ( $peer->wants($yec) ) { 

		#$peer -> notify($tick) ;
		printf "Peer with id %s Notified\n" , $peer ;

	    #}
				
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

sub serverListUrl {

    my $self = shift ;
    my $arg = shift ;
    $self->{ 'serverListUrl'} = $arg if ( $arg ) ;
    return $self->{ 'serverListUrl'} ;

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
sub clistener {

    my $self = shift ;

    my @serverlist = NodeCore::getServerList( $self -> {"serverListUrl"} ) ;

    my $readServer_set = new IO::Select();

    if ( $#serverlist < 0 ) {
	warn "Couldnt find a list of servers\n" ;
	return ;
    }
    $self->serverListAdd( @serverlist ) ;
    print "Found $#serverlist+1 nodes to connect to\n" ;
    
    while (1) {

	# Try servers in the list until we reach $MIN_SERVERS
	# of course if serverlist is smaller than $MIN_SERVERS
	# then serverlist size applies
	printf "Node::clistener connected to %s servers\n", $readServer_set->count() ;
	while ( $readServer_set->count() < $MIN_SERVERS && 
		$readServer_set->count() < $#serverlist ) {

	    foreach ( @{$self->{serverlist}}) {
		printf "Connecting to %s:%s\n" , $_->{'servername'},$_->{'port'} ;

		my ($s, $tmpid) = NodeCore::connectToServer($_, $clientid) ;

		# create handle set for reading
		if ( $s ) {
		    $clientid = $tmpid ;
		    my $peer = gethostbyaddr($s->peeraddr,"AF_INET") || $s->peerhost;
		    printf "Node::clistener Connected to %s and with an id $clientid\n", $peer ;
		    $readServer_set->add($s);
		    print "Node::clistener adding new server to the list of connected servers\n" ;
		    push @{$cserverlist} , $_->{'servername'} . ":" . $_->{'port'} ;
		    # add the main socket to the set
		}
	    }
	    #warn "We are not connected to a server, wait and retry\n" ;
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

    warn "Node::clistener ENDS!!!!\n" ;
    return ;
    # simulate some real traffic ...
    my $myEntity = Entity -> new( yec => "WEA.MADRID" ) ;

}

# This is the server listener ...
# Waits for connections from :
# - Nodes in the network
# - SuperNodes
sub slistener {
    my $self = shift ;
    my $port = $self->{sport} || 5555 ;
    my $ss = NodeCore::snodeListenSocket( $port ) ;
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
			print "Node::slistener() Lets reply with an RHELO ...\n";
			print $rh "RHELO\n" ;

			# Check if this has a client id already
			# if not provide one
			my $clid ;
			if ( $buf =~ /HELO\ (.+)/ ) {
			    $clid = $1 ;
			    print $rh "CLID $1\n" ;			    

			} else {
			    $clid = int( 1000000 * rand() ) ;
			    print $rh "CLID $clid\n" ;
			}
			print $rh "CLID $clid\n" ;	
			push ( @peers, $clid ) ;
			push ( @{$self->{peers}}, $rh ) ;
		    }
		}
		else { 
                    # the client has closed the socket
		    # remove the socket from the $read_set and close it
		    print "Node::slistener closes connection\n" ;
		    $readNode_set->remove($rh);
		    close($rh);
		}

	    }
	}
    }
    
}    

sub serverListAdd {
    my $self = shift ;
    my @serverlist = @_ ;

    my @newlist = @{$self->{serverlist }};

    my %control ;
    
    
    for ( @newlist ) {
	my $tmpkey = $_->{'servername'} . ":" . $_->{'port'} ;
	$control{$tmpkey} = 1 ;
    }

    # Ensure we are not duplicating entries
    # so store in the newlist only new entries
    for (@serverlist) {
	my $tmpkey = $_->{'servername'} . ":" . $_->{'port'} ;
	push @newlist, $_ if ( ! $control{$tmpkey} ) ;
    } 

    $self->{serverlist} = \@newlist ;
    return @newlist ;
}

sub stats {


    while(1) {
	my @cserverlist = @{$cserverlist} ;
	print "We are clientid $clientid connected to : $#cserverlist + 1 servers\n" ;
	my $tmp = 1 ;
	for (@cserverlist) { print "Server $tmp: $_\n" ; $tmp++; } 
	sleep(10) ;
    }

}

1 ;

