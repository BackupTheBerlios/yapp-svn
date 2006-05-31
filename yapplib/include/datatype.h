/**

  datatype.h - Copyright enrique

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

#ifndef DATATYPE_H
#define DATATYPE_H
#include <string>

/**
 * Class dataType
 * This is an abstract data type of which several data
 * entities may link. 
 * It should be the main parent of any data type that is
 * created thereafter. Some examples should be provided
 * 
 */
class dataType {
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
  dataType ( ) { }
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
   string type;
   string description;
   string dtemplate;
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
  string get_type ( );
    
  
  /**
   * 
   */
  void set_type (string value );
    
  
  /**
   * 
   */
  string get_description ( );
    
  
  /**
   * 
   */
  void set_description (string value );
    
  
  /**
   * 
   */
  string get_dtemplate ( );
    
  
  /**
   * 
   */
  void set_dtemplate (string value );
    
  
};
#endif //DATATYPE_H

