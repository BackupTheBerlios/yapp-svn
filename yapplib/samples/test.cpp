#include <iostream>
#include "yappiclient.h" 

int main( int argc, char* argv[] ) {

  yappiClient *yc = yappiClient() ;
  cout << yc->get_id() ;
  return 0 ;


}
