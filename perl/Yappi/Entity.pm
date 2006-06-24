package Entity ;

###############################################################################################################################
sub new {
    my ($class, %args) = @_;
    my $yec = $args{ yec } ;
    my $self = {
	'yec' => $yec 
    } ;
    bless $self, $class;
    return $self ;
}
###############################################################################################################################

sub createTick {
    my ($self, %data) = @_;

    #printf "Creating tick for entity %s\n", $self->{'yec'} ; 
    my $tick = new Yappi::Tick ;
    
    for (keys  %data ) {
	# printf "Setting %s = %s \n", $_,$data{$_} ;
	$tick->{$_} = $data{$_} ;
	$tick -> {time} = time ;

    }
    $tick->{'yec'} = $self->{'yec'} ;
    # Attach a reference to the entity that created us
    $tick -> {'entity'} = $self ;
    return $tick ;

}

1 ;
