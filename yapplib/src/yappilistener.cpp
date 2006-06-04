/**

  yappilistener.cpp - Copyright (c) 2006 Todsawat Thongsuk (todsawatt@hotmail.com)

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

#include "yappilistener.h"

BEGIN_EVENT_TABLE(CYappiListener, wxEvtHandler)
    EVT_SOCKET(wxID_ANY, CYappiListener::OnSocketEvent)
END_EVENT_TABLE()

CYappiListener::CYappiListener(wxIPaddress &addr)
 : wxSocketServer(addr, wxSOCKET_NOWAIT | wxSOCKET_REUSEADDR)
{
    if (Ok()) {
        SetEvtHandlerEnabled(true);
        SetEventHandler(*this);      
        SetNotify(wxSOCKET_CONNECTION_FLAG);
        Notify(true);
        
        //TODO: Succeed
    } else {
        //TODO: Cannot open a TCP socket
    }
}

CYappiListenSocket::~CYappiListenSocket() 
{
    Discard();
    Close();
 
bool CYappiListenSocket::StartListening()
{
    //TODO 
    return true;
}
 
void CYappiListenSocket::StopListening()
{
    //TODO
}

void CListenSocket::AddConnection(CYappiConnection* connection)
{
    wxASSERT(connection);
    m_yappiConnection_list.insert(connection);
}

void CListenSocket::RemoveConnection(CYappiConnection* connection)
{
    wxASSERT(connection);
    m_yappiConnection_list.erase(connection);
}

void CYappiListenSocket::OnAccept(wxSocketEvent& event) 
{
    CYappiConnection* newconnection = new CYappiConnection();
    if (!AcceptWith(*newconnection, false)) {
        newclient->Safe_Delete();
    } else {
        AddConnection(newconnection);
    }
}

void CYappiListenSocket::OnSocketEvent(wxSocketEvent& event) 
{
	switch (event.GetSocketEvent()) {
  	    case wxSOCKET_CONNECTION:
    		OnAccept(event);
		    break;
    }
}
