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
my $yappi_node = Node->new( -interface => '192.168.1.2',
				 -min_sconnections => 2,
				 -ping_timeout => 60
				 ) ;  

# The library will call this
# function every time new data is available
$yappi_node -> updateCallback ( \&newData ) ;

# The library will call this function
# with the relevant parameter to send isntuctions 
# notifications or pings to us.
$yappi_node -> statusCallback ( \&newStatus ) ;

$yappi_node -> subscribe ( "WEA.MADRID" ) ;
$yappi_node -> subscribe ( "WEA.THONEX" ) ;

# And this is the new data entity for the
# data we would like to publish:
my $myEntity = Entity -> new( -yec => "WEA.COLLONGESOUSALEVE" ) ;

while (1) {
    print "While 1 \n" ;
    sleep 1;
    
    # Every minute show the last data we received
    &showLastData("WEA.MADRID") ;

    # And every minute publish some weather data at our place
    my $frogdata = Froggy::LastDate ;


    # and we publish some data ourselves too ...
    my $newtick = $myEntity->createTick ( -temperature => $frogdata->{temperature},
					  -humidity => $frogdata->{humidity}  ) ;

    $yappi_node -> sendupdate( $newtick ) ; 
    
}

sub newData {

    my $tick = shift ;

    # First validate this tick
    if ( ! $tick -> validate() ) {
	&raiseError ( "Data for YEC: " . $tick -> yec . " doesnt pass validation check." .
		     "The error is: " . $tick -> validationErrorStr );
    }
    
    # $tick -> yec always exist. If this is weather data then we
    # will be able to access things like location and temperature
    if ( $tick -> yec =~ /WEA\..*/ ) {

	# This always exists for a tick
	my $time = $tick -> time ;

	# and now the WEA specific data
	my $location = $tick -> location ;
	my $temperature = $tick -> temperature ;
	my $humidity = $tick -> himidity ;
	print 
	    "Weather in $location at $time: $temperature ".
	    "and $humidity humidity \n" ;
    }

    print "We have received this number of updates: " . 
	$yappi_node -> subscriptions ( $tick -> yec ) -> updatecount ;
    
    
}


sub showLastData{

    my $yec = shift ;
    my $ticklist = $yappi_node -> subscriptions ( $yec ) -> ticks ;
    print "Showlast data \n" ;
    my @ticklist = @{$ticklist} ;
    my $count = 10 ;



    # Do we have already $count points to show ? check
    $count = $#ticklist if ( $#ticklist < $count ) ;

    print "Showing last $count data for $yec : \n" ;
    for ( my $i=$#ticklist - $count , $i == $#ticklist, $i++ ) {
	
	print $yec . $ticklist[$i] -> {'time'} . $ticklist[$i] -> {'temperature'} . "\n " ;
    }

}

sub raiseError {

    $lastError = shift ;

}
