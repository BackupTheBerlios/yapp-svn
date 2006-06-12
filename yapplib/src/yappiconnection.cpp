/**

  yappiconnection.cpp - Copyright enrique
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

#include "yappiconnection.h"

/***********************************************************************************************************
 * The CYappiConnectionHandler class: Using for handling the socket event for connection. 
 *                                    Every connection can share a event handler in order to save memory.
 ***********************************************************************************************************/

class CYappiConnectionHandler: public wxEvtHandler {
public:
	CYappiConnectionHandler() {};
private:
	void OnSocketEvent(wxSocketEvent& event);
	DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(CYappiConnectionHandler, wxEvtHandler)
	EVT_SOCKET(wxID_ANY /* TODO: define a ID */, CYappiConnectionHandler::OnSocketEvent)
END_EVENT_TABLE()

void CYappiConnectionHandler::OnSocketEvent(wxSocketEvent& event)
{
	CYappiConnection *connection = dynamic_cast<CYappiConnection *>(event.GetSocket());
	wxASSERT(connection);
	if (!connection) {
		return;
	}
 
	if (connection->OnDestroy()) {
		return;
	}
       
	switch(event.GetSocketEvent()) {
		case wxSOCKET_CONNECTION:
			connection->OnConnect(wxSOCKET_NOERROR);
			break;
		case wxSOCKET_LOST:
			connection->OnError(connection->LastError());
			break;
		case wxSOCKET_INPUT:
			connection->OnReceive(wxSOCKET_NOERROR);
			break;
		case wxSOCKET_OUTPUT:
			connection->OnSend(wxSOCKET_NOERROR);
			break;
		default:
			wxASSERT(0);
			break;
	}   
}

// declare a global variable of the Yappi connection event handler
static CYappiConnectionHandler g_yappiConnectionHandler;

/************************************************************************************************************
 * The CYappiConnection class: Using for keeping every status of each connection. The callback functions will 
 *                             will be called from g_yappiConnectionHandler operating as an event dispatcher. 
 ************************************************************************************************************/

IMPLEMENT_DYNAMIC_CLASS(CYappiConnection, wxSocketClient)

/**
 * Constructors/Destructors
 */

CYappiConnection::CYappiConnection() 
	: wxSocketClient(wxSOCKET_NOWAIT)  
{
	SetConnectionTimeOut(CONNECTION_TIMEOUT); // Set timeout to the default
    SetConnectionState(0);

	SetEventHandler(g_serverSocketHandler, -1 /* TODO: to add ID*/);
         
	SetNotify(
		wxSOCKET_CONNECTION_FLAG |
		wxSOCKET_INPUT_FLAG |
		wxSOCKET_OUTPUT_FLAG |
		wxSOCKET_LOST_FLAG);

	Notify(TRUE);
}

CYappiConnection::~CYappiConnection() 
{
	SetNotify(0);
	Notify(FALSE);
}

/**
 * Methods
 */

void  CYappiConnection::OnConnect(wxUint32 nErrorCode) 
{
}

void  CYappiConnection::OnSend(wxUint32 nErrorCode) 
{
	if (nErrorCode){
		OnError(nErrorCode);
		return;
	}
}

void  CYappiConnection::OnReceive(wxUint32 nErrorCode) 
{
	if(nErrorCode) {
		wxUint32 error = LastError(); 
		if (error != wxSOCKET_WOULDBLOCK) {
			OnError(nErrorCode);
			return;

		}
	}
}

void CServerSocket::setConnectionState(sint8 newstate) 
{
	m_connection_state = state;

    //TODO: To do action for the new staus
}

wxUint32 CServerSocket::getConnectionTimeOut() 
{
	return m_timeout;
}

void CServerSocket::SetConnectionTimeOut(wxUint32 timeout) 
{
	m_timeout = timeout;
}
