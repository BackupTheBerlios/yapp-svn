package Subscription ;

###############################################################################################################################
sub new {
    my ($class, %args) = @_;
    my $yec = $args{ 'yec' } ;
    my $id = $args{ id } ;
    my $self = {
	yec => $yec ,
	ticks => [] 
    } ;
    # print "Subscription::new  subscribed to $yec \n" ;
    bless $self, $class;
    return $self ;
}

sub ticks {
    my $self = shift ;
    return $self->{'ticks'};

}


1 ;
