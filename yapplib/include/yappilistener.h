/**

  yappilistener.h - Copyright (c) 2006 Todsawat Thongsuk (todsawatt@hotmail.com)

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

// SVN_ID: $Id$

#ifndef YAPPILISTENER_H
#define YAPPILISTENER_H

#include <set> 

#include <wx/socket.h>   // For wxSocketServer
#include <wx/defs.h>     // For wxUint32

class CYappiConnection;

class CYappiListener : public wxSocketServer, public wxEvtHandler {
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
	CYappiListener(wxIPaddress &addr);
	~CYappiListener(); 
	/**
	 * Accessor Methods
	 */
	/**
	 * Operations
	 */
	/**
	 * Start the listener in order to accept the client connection
	 */
	bool StartListening();
	/**
	 * Stop the listener in order not to accept the client connection
	 */
	void StopListening();

	wxUint32 GetNumberOpenSockets() { return m_yappiConnection_list.size(); }
	void AddConnection(CYappiConnection* connection);
	void RemoveConnection(CYappiConnection* connection);
  
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
	void OnSocketEvent(wxSocketEvent& event);
	void OnAccept(wxUint8 nErrorCode);
  
/**
 * Private stuff
 */
private:
	/**
	 * Fields
	 */
	std::set<CYappiConnection *> m_yappiConnection_list;
	/**
	 * 
	 */
	/**
	 * Constructors
	 */
	/**
	 * Accessor Methods
	 */
	
	DECLARE_EVENT_TABLE();

};
#endif //YAPPILISTENER_H
