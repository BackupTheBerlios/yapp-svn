/**

  dataevent.h - Copyright enrique

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

#ifndef DATAEVENT_H
#define DATAEVENT_H
#include <string>
#include "dataentity.h"
#include "datatick.h"
#include "yappinode.h"

class dataEvent {
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
  dataEvent ( ) { }
  /**
   * Accessor Methods
   */
/**
 * Protected stuff
 */
protected:
  /**
   * Fields
   */
  /**
   * Contributor is the Client ID of the original contributor
   */
   yappiNode contributor;
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
   * Get the value of contributor
   * Contributor is the Client ID of the original contributor
   * @return the value of contributor
   */
  yappiNode get_contributor ( );
    
  
  /**
   * Set the value of contributor
   * Contributor is the Client ID of the original contributor
   * @param value the value of contributor
   */
  void set_contributor (yappiNode value );
    
  
/**
 * Private stuff
 */
private:
  /**
   * Fields
   */
   dataEntity evDEntity;
   dataTick data;
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
   * 
   */
  dataEntity get_evDEntity ( );
    
  
  /**
   * 
   */
  void set_evDEntity (dataEntity value );
    
  
  /**
   * 
   */
  dataTick get_data ( );
    
  
  /**
   * 
   */
  void set_data (dataTick value );
    
  
};
#endif //DATAEVENT_H

