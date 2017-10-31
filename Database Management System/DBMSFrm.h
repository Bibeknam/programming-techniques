///-----------------------------------------------------------------
///
/// @file      DBMSFrm.h
/// @author    bunkdeath
/// Created:   5/25/2010 10:38:11 AM
/// @section   DESCRIPTION
///            DBMSFrm class declaration
///
///------------------------------------------------------------------




#ifndef __DBMSFRM_H__
#define __DBMSFRM_H__

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
#include <wx/button.h>
////Header Include End

////Dialog Style Start
#undef DBMSFrm_STYLE
#define DBMSFrm_STYLE wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class DBMSFrm : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		DBMSFrm(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("DBMS"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = DBMSFrm_STYLE);
		void btnCreateClick(wxCommandEvent& event);
		virtual ~DBMSFrm();
		
		wxString current_wd;  // current working directory set.
		void btnSelectClick(wxCommandEvent& event);
		void WxButton1Click(wxCommandEvent& event);
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxButton *btnSelect;
		wxButton *btnCreate;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_BTNSELECT = 1002,
			ID_BTNCREATE = 1001,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif
