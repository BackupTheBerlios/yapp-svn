package Tick ;

###############################################################################################################################
sub new {
    my ($class, %args) = @_;
    my $id = $args{ id } ;
    my $self = {	
	} ;
    bless $self, $class;
    return $self ;
}

sub yec {

    my $self = shift ;
    return $self -> {entity} -> {yec} ;

}

sub validate {

    my $self = shift ;
    return 1 ;

}

1;
