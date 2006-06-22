package Entity ;

###############################################################################################################################
sub new {
    my ($class, %args) = @_;
    my $id = $args{ id } ;
    my $self = {
    } ;
    bless $self, $class;
    return $self ;
}
###############################################################################################################################

sub createTick {

    my $self = shift ;
    my %data = %{shift} ;

    my $tick = new Yappi::Tick ;
    foreach (keys  %data ) {

	$tick->{'$_'} = $data{'$_'} ;

    }
    return $tick ;

}

1 ;
