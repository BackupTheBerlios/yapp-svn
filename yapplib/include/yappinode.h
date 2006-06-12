/**

  yappinode.h - Copyright enrique 
                Copyright (c) 2006 Todsawat Thongsuk (todsawatt@hotmail.com)

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

// SVN-ID: $Id$

#ifndef YAPPINODE_H
#define YAPPINODE_H

#include <wx/socket.h>
#include "yappilistener.h"

class CYappiNode {
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
  CYappiNode ( ) { }
  ~CYappiNode ( ) { }
  /**
   * Accessor Methods
   */
  /**
   * Operations
   */
  /**
   * Start the listener in order to accept the client connection
   */
  void startListener (wxIPaddress &addr);
  
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
  CYappiListener *m_yappiListener;
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
#endif //YAPPINODE_H

