package NodeCore ;

use strict ;
use LWP::UserAgent;
use XML::LibXML ;
use IO::Select;
use IO::Socket;
# This is 
sub snodeListenSocket {

    my $s = new IO::Socket::INET
	(
	 LocalHost => "0.0.0.0",
	 LocalPort => 5555,
	 Proto => 'tcp',
	 Listen => 16,
	 Reuse => 1,
	 );
    warn "Coulnt not open listeing snode listen socket: $! \n" unless $s ;
}

sub connectToServer {

    my $snode = shift  ;
    my $clientid = shift ;
    my $server= $snode->{'servername'};
    my $port = $snode->{'port'} ;
	
    my $sock = new IO::Socket::INET 
	(
	 PeerAddr => $server,
	 PeerPort => $port,
	 Proto => 'tcp',
	 );

    my $clientid ;
    if ( $sock ) {

	if ( $clientid ) {
	    print $sock "GET /HELO $clientid\n" ;
	} else {
	    print $sock "GET /HELO\n" ;
	}

	print "NodeCore::connectToServer send HELO waiting RHELO msg\n";

	while ( my $res = <$sock> ) {
	    chop $res;
	    warn "NodeCore::connectToServer Parsing one line of input '$res'\n" ;
	    if ( $res =~ /CLID\ (.*)/ ) {
		$clientid = $1 ;	       
		print "This is clientid $clientid\n" ;
		return ($sock, $clientid) ;
	    }

	    elsif ( $res =~ /^RHELO/ ) {
		print "NodeCore::connectToServer Reply RHELO received, wait for client id\n" ;
		
	    }

	    else {
		warn "Reply from server not understood\n" ;
		return;
	    }
	}
	
	
    } else {  # No socket
	
	printf "Couldnt connect to server %s:%s :$!\n", $server, $port ;
	return ;
	
    }
    
}

sub getServerList {

    my $ua = &yappiUserAgent() ;
    my $YSLURL = shift || "http://www.yappi.org/serverlist.xml" ;

    # Create a request
    my $req = HTTP::Request->new(GET =>$YSLURL);
    
    # Pass request to the user agent and get a response back
    my $res = $ua->request($req);

    # Check the outcome of the response
    if ($res->is_success) {

	my $parser = XML::LibXML->new();
	# read the DOM
	my $dom    = $parser->parse_string( $res->content );

	# get the ROOT Element of the DOM
	my $elem   = $dom->getDocumentElement();

	# test if the element has the correct node type ...
	if ( $elem->getType() == XML_ELEMENT_NODE ) {

	    # ... and the correct name
	    if ( $elem->getName() eq "yappiNodeList" ) {
		my @nodelist ;
		# find class definitions without XPath :-P
		foreach my $child ( $elem->getElementsByTagName("node") ) { 

		    push @nodelist, &nodeXml2Hash($child) ;
		}
		return @nodelist ;
	    }
	    else {
		warn "ERROR> document is not a node list! \n";
		return ;
	    }
	}
	else {
	    warn "Error retrieving server list: " . $res->status_line, "\n";
	    return ;
	}
    }

}

sub nodeXml2Hash {

    my $node = shift ;
    my %ynode ;
    
    $ynode{servername} = $node->getAttribute( "servername" ) ;
    $ynode{port} = $node->getAttribute( "port" ) ;
    
    printf "Found node %s:%s \n",$ynode{servername}, $ynode{port};

    return \%ynode;
    

}

sub yappiUserAgent {

    my $ua = LWP::UserAgent->new;
    $ua->agent("YappiCore/0.1 ");

    return $ua ;

}


1;
