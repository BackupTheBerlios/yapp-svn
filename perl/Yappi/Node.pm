package Node ;
use threads;
use threads::shared;
use Yappi::NodeCore ;
use Yappi::Subscription; 
###############################################################################################################################
sub new {
    my ($class, %args) = @_;
    my $id = $args{ id } ;
    my $self = {
	subscriptions => {} 
	} ;
    bless $self, $class;
    return $self ;
}

sub dummy {
    
    while(1){ print "Hola\n" ; sleep 2; }

}


sub start {

    my $self = shift ;
    my $bar = &share([]);
    $self{bar} = &share({});

    my $thr = new threads \&listener, $self ;
    print "Yappi::Node And now detach the newly created listener thread\n" ;
    $thr->detach;

    my $sthr = new threads \&slistener, $self ;
    print "Yappi::Node And now detach the newly created server listener thread\n" ;
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
	return $self->{'subscriptions'}->{$yec} ;
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
    my $readServer_set;

    if ( $#serverlist < 0 ) {
	warn "Couldnt find a list of servers\n" ;
	return ;
    } else {
	
	print "Found $#serverlist+1 nodes to connect to\n" ;
	for ( @serverlist) {
	    printf "Connecting to %s:%s\n" , $_->{'servername'},$_->{'port'} ;
	    my $s = NodeCore::connectToServer($_) ;
	    $readServer_set = new IO::Select(); 
            # create handle set for reading
	    $readServer_set->add($s);           
            # add the main socket to the set
	}

	while (1) { # forever
	    # get a set of readable handles (blocks until at least one handle is ready)
	    print "Node::listener waiting for input \n" ;
	    my $rh_set = IO::Select->select($read_set, undef, undef, 0);
	    # take all readable handles in turn

	    foreach $rh (@$rh_set) {
		# if it is the main socket then we have an incoming connection and
		# we should accept() it and then add the new socket to the $read_set
		#if ($rh == $s) {
		#    $ns = $rh->accept();
		#    $read_set->add($ns);
		#}
		# otherwise it is an ordinary socket and we should read and process the request
		#else {
		$buf = <$rh>;
		if($buf) { # we get normal input
		    # ... process $buf ...
		    print "Server says $buf\n" ;
		}
		else { # the client has closed the socket
		    # remove the socket from the $read_set and close it
		    $read_set->remove($rh);
		    close($rh);
		}
		#}
	    }
	}
	
	
    } 

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
sub slistener {
    my $ss = NodeCore::snodeListenSocket() ;
    my ($ns, $buf);
    while( $ns = $ss->accept() ) { # wait for and accept a connection
	print "Node::slistener Someone has connected\n" ;
	while( defined( $buf = <$ns> ) ) { # read from the socket
	    print "Node::slistener It says $buf\n" ;
	    if ( $buf =~ /GET\ \/HELO/ ) {
		print "Lets reply with an RHELO ...";
		print $ns "RHELO\n" ;
		print $ns "CLID 123123123\n" ;
		print "reply sent\n" ;
	    } else {

	    }
	    # do some processing
	}
    }
    close($s);
}

1 ;

