/**

  yappiserver.h - Copyright enrique

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

#ifndef YAPPISERVER_H
#define YAPPISERVER_H
#include <string>

class yappiServer {
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
  yappiServer ( ) { }
  /**
   * Accessor Methods
   */
  /**
   * Operations
   */
  /**
   * 
   */
  void listenConnection ();
    
  
  /**
   * 
   */
  void localSearch ();
    
  
  /**
   * 
   */
  void forwardSearch ();
    
  
  /**
   * 
   */
  void newData ();
    
  
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
   int connections;
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
  int get_connections ( );
    
  
  /**
   * 
   */
  void set_connections (int value );
    
  
  /**
   * Operations
   */
};
#endif //YAPPISERVER_H

