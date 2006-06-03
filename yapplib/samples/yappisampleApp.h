//---------------------------------------------------------------------------
//
// Name:        yappisampleApp.h
// Author:      Todsawat Thongsuk
// Created:     $Id$
// Description: This sample is programmed on wxDev-C++, Microsoft Windows
//
//---------------------------------------------------------------------------

#ifndef __yappisampleApp_h__
#define __yappisampleApp_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

class yappiSampleApp : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};

#endif
