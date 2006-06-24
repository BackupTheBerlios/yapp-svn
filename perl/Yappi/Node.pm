package Node ;
use threads;
use threads::shared;
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
    print "Yappi::Node Create new thread\n" ;
    #my $thr = threads->create( \&dummy ) ;

    my $thr = new threads \&listener, $self ;
    print "Yappi::Node And now detach the newly created thread\n" ;
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

sub listener {

    my $self = shift ;

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

1 ;

