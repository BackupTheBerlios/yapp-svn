package Subscription ;

###############################################################################################################################
sub new {
    my ($class, %args) = @_;
    my $yec = shift ;
    my $id = $args{ id } ;
    my $self = {
	yec => $yec ,
	ticks => {} ;
    } ;
    bless $self, $class;
    return $self ;
}

sub ticks {
    my $self = shift ;
    return $self->{'ticks'};

}


1 ;
