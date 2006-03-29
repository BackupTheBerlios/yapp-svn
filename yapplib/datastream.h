/**

  datastream.h - Copyright enrique

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

using namespace std;

#ifndef DATASTREAM_H
#define DATASTREAM_H
#include <string>
#include "datatick.h"

class dataStream {
/**
 * Public stuff
 */
public:
  /**
   * Fields
   */
  /**
   * 
   */
  /**
   * Constructors
   */
  /**
   * Empty Constructor
   */
  dataStream ( ) { }
  /**
   * Accessor Methods
   */
  /**
   * Operations
   */
  /**
   * Injects data to the stream and cascades to the network
   * if there are subscribers.
   */
  int  injectData (dataTick tick);
    
  
  /**
   * Reads more data from this stream.
   * 
   */
  int  readData ();
    
  
/**
 * Protected stuff
 */
protected:
  /**
   * Fields
   */
  /**
   * 
   */
  /**
   * Constructors
   */
  /**
   * Accessor Methods
   */
  /**
   * Operations
   */
/**
 * Private stuff
 */
private:
  /**
   * Fields
   */
  /**
   * This is the last tick that this stream has received or injected.
   */
   dataTick lstTick;
  /**
   * Determines if the data is to be stored as it is read or contributed to the network
   */
   int storable;
  /**
   * 
   */
  /**
   * Constructors
   */
  /**
   * Accessor Methods
   */
  /**
   * Get the value of lstTick
   * This is the last tick that this stream has received or injected.
   * @return the value of lstTick
   */
  dataTick get_lstTick ( );
    
  
  /**
   * Set the value of lstTick
   * This is the last tick that this stream has received or injected.
   * @param value the value of lstTick
   */
  void set_lstTick (dataTick value );
    
  
  /**
   * Get the value of storable
   * Determines if the data is to be stored as it is read or contributed to the network
   * @return the value of storable
   */
  int get_storable ( );
    
  
  /**
   * Set the value of storable
   * Determines if the data is to be stored as it is read or contributed to the network
   * @param value the value of storable
   */
  void set_storable (int value );
    
  
  /**
   * Operations
   */
};
#endif //DATASTREAM_H

