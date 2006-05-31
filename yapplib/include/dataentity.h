/**

  dataentity.h - Copyright enrique

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

#ifndef DATAENTITY_H
#define DATAENTITY_H
#include <string>

/**
 * Class dataEntity
 * This is the data Reality to which a data event is linked:
 * consumer price in Germany or Temperature at my place.
 */
class dataEntity {
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
  dataEntity ( ) { }
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
   * 
   */
  /**
   * Constructors
   */
  /**
   * Accessor Methods
   */
/**
 * Private stuff
 */
private:
  /**
   * Fields
   */
   string deName;
   string deDescription;
   int deLastUpdate;
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
  string get_deName ( );
    
  
  /**
   * 
   */
  void set_deName (string value );
    
  
  /**
   * 
   */
  string get_deDescription ( );
    
  
  /**
   * 
   */
  void set_deDescription (string value );
    
  
  /**
   * 
   */
  int get_deLastUpdate ( );
    
  
  /**
   * 
   */
  void set_deLastUpdate (int value );
    
  
};
#endif //DATAENTITY_H

