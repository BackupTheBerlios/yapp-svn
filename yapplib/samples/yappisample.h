//---------------------------------------------------------------------------
//
// Name:        yappisample.h
// Author:      Todsawat Thongsuk
// Created:     $Id$
// Description: This sample is programmed on wxDev-C++, Microsoft Windows
//
//---------------------------------------------------------------------------

#ifndef __YAPPISAMPLE_h__
#define __YAPPISAMPLE_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
#include <wx/textctrl.h>
////Header Include End

////Dialog Style Start
#undef yappiSample_STYLE
#define yappiSample_STYLE wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxTHICK_FRAME | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class CYappiNode;

class yappiSample : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		yappiSample(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Yappi Sample"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = yappiSample_STYLE);
		virtual ~yappiSample();
		
	public:
		//Do not add custom control declarations
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxTextCtrl *WxMemo1;
		////GUI Control Declaration End
		
	public:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_WXMEMO1 = 1002,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	public:
		void yappiSampleClose(wxCloseEvent& event);
		void CreateGUIControls(void);
		
	private:
        CYappiNode *m_yappiNode;
};

#endif
