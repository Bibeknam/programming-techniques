//---------------------------------------------------------------------------
//
// Name:        Untitled1Frm.h
// Author:      bunkdeath
// Created:     7/15/2010 9:28:59 AM
// Description: Untitled1Frm class declaration
//
//---------------------------------------------------------------------------

#ifndef __UNTITLED1FRM_h__
#define __UNTITLED1FRM_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
////Header Include End

////Dialog Style Start
#undef Untitled1Frm_STYLE
#define Untitled1Frm_STYLE wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class Untitled1Frm : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		Untitled1Frm(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Untitled1"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = Untitled1Frm_STYLE);
		virtual ~Untitled1Frm();
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif
