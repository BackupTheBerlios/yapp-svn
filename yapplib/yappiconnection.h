/**

  yappiconnection.h - Copyright enrique

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

#ifndef YAPPICONNECTION_H
#define YAPPICONNECTION_H
#include <string>

class yappiConnection {
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
  yappiConnection ( ) { }
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
   * Contains the IP address of the remote node
   */
   string remoteNode;
  /**
   * Indicates possible status:
   * 1. Active
   * 2. Stale
   * 3. Resetting
   * 4. Unknown
   */
   int status;
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
   * Get the value of remoteNode
   * Contains the IP address of the remote node
   * @return the value of remoteNode
   */
  string get_remoteNode ( );
    
  
  /**
   * Set the value of remoteNode
   * Contains the IP address of the remote node
   * @param value the value of remoteNode
   */
  void set_remoteNode (string value );
    
  
  /**
   * Get the value of status
   * Indicates possible status:
   * 1. Active
   * 2. Stale
   * 3. Resetting
   * 4. Unknown
   * @return the value of status
   */
  int get_status ( );
    
  
  /**
   * Set the value of status
   * Indicates possible status:
   * 1. Active
   * 2. Stale
   * 3. Resetting
   * 4. Unknown
   * @param value the value of status
   */
  void set_status (int value );
    
  
/**
 * Private stuff
 */
private:
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
};
#endif //YAPPICONNECTION_H

