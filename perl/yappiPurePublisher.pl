#!/usr/bin/perl

# Sample use of the Yappi library
# This sample program subscribes to the stream of updates
# with the weather in Madrid, Yappi Entity Code for this is "WEA.MADRID"
# 
# 

use lib './', '/home/http/public/yappi' ;
use Yappi ;
use Yappi::Node ;
use Yappi::Entity ;

my $lastError ;

# Client Initialization
my $yappi_node = Node->new( interface => '192.168.1.2',
			    min_sconnections => 2,
			    ping_timeout => 60
			    ) ;  

# And this is the new data entity for the
# data we would like to publish:
my $myEntity = Entity -> new( -yec => "WEA.COLLONGESOUSALEVE" ) ;

while (1) {
    sleep 1;
    
    # And every minute publish some weather data at our place
    my $frogdata = Froggy::LastDate ;


    # and we publish some data ourselves too ...
    my $newtick = $myEntity->createTick ( temperature => $frogdata->{temperature},
					  humidity => $frogdata->{humidity}  ) ;

    $yappi_node -> sendUpdate( $newtick ) ; 
    
}

sub raiseError {

    $lastError = shift ;

}
