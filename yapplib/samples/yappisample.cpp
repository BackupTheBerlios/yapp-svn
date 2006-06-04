//---------------------------------------------------------------------------
//
// Name:        yappisample.cpp
// Author:      Todsawat Thongsuk
// Created:     $Id$
// Description: This sample is programmed on wxDev-C++, Microsoft Windows
//
//---------------------------------------------------------------------------

#include "yappisample.h"

#include "yappiNode.h"

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// yappiSample
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(yappiSample,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(yappiSample::yappiSampleClose)
END_EVENT_TABLE()
////Event Table End

yappiSample::yappiSample(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
	
	m_yappiNode = new CYappiNode();
	
	wxIPV4address myaddr;
	myaddr.AnyAddress();
	myaddr.Service(1234);
	m_yappiNode->startListener(myaddr);
}

yappiSample::~yappiSample() {
//    m_yappiNode->destroy();                            
}

void yappiSample::CreateGUIControls(void)
{
	//Do not add custom code here
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	this->SetSize(8,8,322,334);
	this->SetTitle(wxT("Yappi Sample"));
	this->Center();
	this->SetIcon(wxNullIcon);
	

	WxMemo1 = new wxTextCtrl(this, ID_WXMEMO1, wxT(""), wxPoint(0,4), wxSize(313,294), wxTE_MULTILINE, wxDefaultValidator, wxT("WxMemo1"));
	WxMemo1->SetMaxLength(0);
	WxMemo1->AppendText(wxT("Welcome to Yappi Sample:"));
	WxMemo1->SetFocus();
	WxMemo1->SetInsertionPointEnd();
	////GUI Items Creation End
}

void yappiSample::yappiSampleClose(wxCloseEvent& event)
{
    Destroy();
}
 
