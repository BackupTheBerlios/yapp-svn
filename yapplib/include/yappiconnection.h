/**

  yappiconnection.h - Copyright enrique
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

#ifndef YAPPICONNECTION_H
#define YAPPICONNECTION_H

#include <wx/socket.h>   // For wxSocketClient
#include <wx/defs.h>     // For wxUint8

#define CONNECTION_TIMEOUT 40000 // Default timeout of the connection

class CYappiConnection: public wxSocketClient {

	DECLARE_DYNAMIC_CLASS(CYappiConnection)

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
	CYappiConnection();
	virtual ~CYappiConnection();
	/**
	 * Accessor Methods
	 */
	wxUint8 getConnectionState() { return m_connection_state; }

	virtual void  OnConnect (wxUint32 nErrorCode); 
	virtual void  OnError (wxUint32 nErrorCode) { }; 
	virtual void  OnSend (wxUint32 nErrorCode); 
	virtual void  OnReceive (wxUint32 nErrorCode);  

	wxUint32 getConnectionTimeOut();	     
	void setConnectionTimeOut(wxUint32 timeout);

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
	void resetConnectionTimer();


/**
 * Private stuff
 */
private:
	/**
	 * Fields
	 */
	wxUint8 m_connection_state;
	wxUint32 m_timeout;
	/**
	 * 
	 */
	/**
	 * Constructors
	 */
	/**
	 * Accessor Methods
	 */
	void setConnectionState(wxUint8 state);

};
#endif //YAPPICONNECTION_H

