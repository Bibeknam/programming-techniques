//---------------------------------------------------------------------------
//
// Name:        DBMSApp.h
// Author:      bunkdeath
// Created:     5/25/2010 10:38:10 AM
// Description: 
//
//---------------------------------------------------------------------------

#ifndef __DBMSFRMApp_h__
#define __DBMSFRMApp_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

class DBMSFrmApp : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};

#endif
