/**

  datatick.h - Copyright enrique

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

#ifndef DATATICK_H
#define DATATICK_H
#include <string>
#include "datatype.h"

class dataTick {
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
  dataTick ( ) { }
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
   int time;
   string xmlData;
   dataType dType;
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
  int get_time ( );
    
  
  /**
   * 
   */
  void set_time (int value );
    
  
  /**
   * 
   */
  string get_xmlData ( );
    
  
  /**
   * 
   */
  void set_xmlData (string value );
    
  
  /**
   * 
   */
  dataType get_dType ( );
    
  
  /**
   * 
   */
  void set_dType (dataType value );
    
  
};
#endif //DATATICK_H

