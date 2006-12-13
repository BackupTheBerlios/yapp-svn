#!/usr/bin/perl

# Sample use of the Yappi library
# This sample program subscribes to the stream of updates
# with the weather in Madrid, Yappi Entity Code for this is "WEA.MADRID"
# 
# 

use lib './', '/home/http/public/yappi' ;

use Yappi::Node ;
use Yappi::Entity ;

my $lastError ;

# Testing something
#my $myEntity = Entity -> new( yec => "WEA.TEST" ) ;
#my $newtick = $myEntity->createTick ( temperature => 25,
#				      humidity => 40,
#				      andmore => 1  ) ;   

#exit ;
# Client Initialization
my $yappi_node = Node->new( interface => '192.168.1.2',
			    min_sconnections => 2,
			    ping_timeout => 60
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
$yappi_node -> setIncomingPort(5556) ;

# You should not do this, normally
$yappi_node -> {'serverEnabled'} = 0 ;
$yappi_node -> start() ;

my %subscriptions =  %{$yappi_node -> subscriptions()} ;

print "$0 Node started, doing other things in the meantime\n" ;

while (1) {
    sleep 5;
    
    # This doenst work as it is in main thread:
    # &showLastData("WEA.MADRID") ;

}

sub newData {

    my $tick = shift ;
    my $yec = $tick -> {yec} ;

    printf "$0 New data for yec %s received\n" ,$yec ; 
    
    if ( $yec =~ /WEA\..*/ ) {

	# This always exists for a tick
	my $time = $tick -> {time} ;

	# and now the WEA specific data
	my $temperature = $tick -> {temperature} ;
	my $humidity = $tick -> {humidity} ;
	print 
	    "$0::newData Weather in $yec at $time:\n" .
	    " temperature is '$temperature' \n".
	    " humidity is '$humidity %' \n" ;
    }
    
    my @ticklist = $yappi_node->history($yec) ;
    printf "$0::new Data we have now %s ticks.\n", $#ticklist ;

    &showLastData("WEA.MADRID") ;
    
}


sub showLastData{

    my $yec = shift ;


    @ticklist = $yappi_node->history($yec) ;
    printf "$0::showLastData: We have %s ticks for $yec.\n", $#ticklist + 1;

    my $i = 0 ;
    foreach $tick ( @ticklist ) {
	
	printf "%s %s@%s: %s C and %s% \n" , 
	$i, $yec , $tick -> {'time'} , 
	$tick -> {'temperature'} , $tick -> {'humidity'};

	$i++ ;

    }
    print "$0::showLastData:End showing data \n" ;
}

sub raiseError {

    $lastError = shift ;

}
