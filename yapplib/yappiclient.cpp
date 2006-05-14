/**

  yappiclient.cpp - Copyright enrique

  YAPPI is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published
  by the Free Software Foundation; either version 2, or (at your
  option) any later version.

  YAPPI is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with YAPPI; see the file COPYING.  If not, write to the
  Free Software Foundation, Inc., 59 Temple Place - Suite 330,
  Boston, MA 02111-1307, USA.

**/

#include "yappi_prec.h"

#include "yappiclient.h"

/**
 * Constructors/Destructors
 */
/**
 * Methods
 */
/**
 * Declare a new stream of data.
 * This should then be notified to the network if we want
 * to make it available to others.
 */
dataStream yappiClient::dataPublish (dataType dtType, string code) {
  
}
/**
 * Used to publish data events. dataPublish allows to 
 * declare a new stream, dataUpdate puts data in the stream.
 */
void yappiClient::dataUpdate (dataTick tick, dataStream dtStream) {
  
}
/**
 * 
 */
string yappiClient::get_id ( ) {
  
}
/**
 * 
 */
void yappiClient::set_id (string value ) {
  
}
/**
 * 
 */
int yappiClient::get_connectStatus ( ) {
  
}
/**
 * 
 */
void yappiClient::set_connectStatus (int value ) {
  
}

