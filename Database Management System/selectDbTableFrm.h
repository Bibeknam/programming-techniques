//---------------------------------------------------------------------------
//
// Name:        selectDbTableFrm.h
// Author:      deathbunk
// Created:     4/25/2010 9:07:33 PM
// Description: selectDbTableFrm class declaration
//
//---------------------------------------------------------------------------

#ifndef __SELECTDBTABLEFRM_h__
#define __SELECTDBTABLEFRM_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif

#include <wx/hyperlink.h>



//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/menu.h>
////Header Include End

////Dialog Style Start
#undef selectDbTableFrm_STYLE
#define selectDbTableFrm_STYLE wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End




class selectDbTableFrm : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		selectDbTableFrm(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("selectDbTable"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = selectDbTableFrm_STYLE);
		virtual ~selectDbTableFrm();

        int out;


		wxButton *btn,*btn1,*btnSelect;
		wxTextCtrl *txtSelect;
		wxHyperlinkCtrl *db[100],*table[100];
		wxHyperlinkCtrl *link[100];
        wxString table_name;
        wxString current_wd,dname;

        void getTables(wxHyperlinkEvent& event);
		void getContens(wxHyperlinkEvent& event);
		
		friend class ClassTable;
		wxString getTableName();
		int nstart;
		
		void Mnuedit1003Click(wxCommandEvent& event);
		void Mnupassword1004Click(wxCommandEvent& event);
        void cwd(wxString);
        
        wxPasswordEntryDialog *Dialog_Password;
        wxPasswordEntryDialog *Dialog_Repassword;
        wxPasswordEntryDialog *Dialog_Oldpassword;
		void Mnudeletetable1006Click(wxCommandEvent& event);
		void Mnuaddtable1007Click(wxCommandEvent& event);
		void Mnudelete1008Click(wxCommandEvent& event);
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxMenuBar *WxMenuBar1;
		////GUI Control Declaration End
//		wxMenuBar *WxMenuBar1;



		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
            ID_TXTSELECT=500,
            ID_BTNSELECT,
			////GUI Enum Control ID Start
			ID_MNU_FILE_1001 = 1001,
			ID_MNU_ADDTABLE_1007 = 1007,
			ID_MNU_DELETE_1008 = 1008,
			ID_MNU_EDIT_1003 = 1003,
			ID_MNU_PASSWORD_1004 = 1004,
			ID_MNU_DELETETABLE_1006 = 1006,
			
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();

        void displayTable(wxString db);
		void btnSelectClick(wxCommandEvent& event);
		void txtSelectUpdated(wxCommandEvent& event);
		void showTables();
		void Password();
		void createpasswordfile();

};

#endif
