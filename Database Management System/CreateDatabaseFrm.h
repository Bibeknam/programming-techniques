///-----------------------------------------------------------------
///
/// @file      CreateDatabaseFrm.h
/// @author    PC_User
/// Created:   4/19/2010 10:52:36 PM
/// @section   DESCRIPTION
///            CreateDatabaseFrm class declaration
///
///------------------------------------------------------------------

#ifndef __CREATEDATABASEFRM_H__
#define __CREATEDATABASEFRM_H__

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
#include <wx/textctrl.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
////Header Include End

////Dialog Style Start
#undef CreateDatabaseFrm_STYLE
#define CreateDatabaseFrm_STYLE wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class CreateDatabaseFrm : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		CreateDatabaseFrm(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Create Database"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = CreateDatabaseFrm_STYLE);
		virtual ~CreateDatabaseFrm();
		void Button_SaveClick(wxCommandEvent& event);
		void Button_CancelClick(wxCommandEvent& event);
		void cwd(wxString);
		void db(wxString);
		int out;
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxButton *Button_Cancel;
		wxButton *Button_SaveDatabase;
		wxTextCtrl *TextBox_RePassword;
		wxTextCtrl *TextBox_Password;
		wxTextCtrl *TextBox_DatabaseName;
		wxStaticText *StaticText_RePassword;
		wxStaticText *StaticText_Password;
		wxStaticText *StaticText_Optional;
		wxStaticBox *StaticBox_Security;
		wxStaticText *WxStaticText1;
		
//		wxString cwd;
		wxString current_wd,dname;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_BUTTON_CANCEL = 1010,
			ID_BUTTON_SAVEDATABASE = 1009,
			ID_TEXTBOX_REPASSWORD = 1008,
			ID_TEXTBOX_PASSWORD = 1007,
			ID_TEXTBOX_DATABASENAME = 1006,
			ID_STATICTEXT_REPASSWORD = 1005,
			ID_STATICTEXT_PASSWORD = 1004,
			ID_STATICTEXT_OPTIONAL = 1003,
			ID_STATICBOX_SECURITY = 1002,
			ID_WXSTATICTEXT1 = 1001,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

class databasestore
{
    private:
        char dname[40];
        char password[40];
    public:
        databasestore(){}
        
      databasestore(wxString dname1,wxString password1)
        {
        strcpy(dname,dname1);
        strcpy(password,password1);
    }
    };


#endif
