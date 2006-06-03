//---------------------------------------------------------------------------
//
// Name:        yappisampleApp.cpp
// Author:      Todsawat Thongsuk
// Created:     $Id$
// Description: This sample is programmed on wxDev-C++, Microsoft Windows
//
//---------------------------------------------------------------------------

#include "yappisampleApp.h"
#include "yappisample.h"

IMPLEMENT_APP(yappiSampleApp)

bool yappiSampleApp::OnInit()
{
    yappiSample* frame = new yappiSample(NULL);
    SetTopWindow(frame);
    frame->Show(true);		
    return true;
}
 
int yappiSampleApp::OnExit()
{
	return 0;
}
