package Node ;

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
###############################################################################################################################
sub updateCallback {
}
###############################################################################################################################
sub statusCallback {
}
###############################################################################################################################
sub subscribe {
		   my $self = shift ;
	       my $yec = shift ;
	       my $subscription = Subscription->new($yec) ;
	       $self->{'subscriptions'}->{$yec} = $subscription ;
		   print "Subscribed to $yec\n" ;
	       return $subscription;
}
###############################################################################################################################
sub subscriptions {
	my $self = shift ;
	my $yec = shift ;
	print "Return subscription for $yec\n" ;
	return $self->{'subscriptions'}->{$yec} ;
}
###############################################################################################################################


sub sendUpdate  {
	my $self = shift ;
	my $tick = shift ;
	
	foreach ( $self -> {'peers' }
	print "Return subscription for $yec\n" ;
	return $self->{'subscriptions'}->{$yec} ;
}

1 ;

