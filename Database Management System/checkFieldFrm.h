///-----------------------------------------------------------------
///
/// @file      checkFieldFrm.h
/// @author    bunkdeath
/// Created:   4/21/2010 10:03:44 PM
/// @section   DESCRIPTION
///            checkFieldFrm class declaration
///
///------------------------------------------------------------------

#ifndef __CHECKFIELDFRM_H__
#define __CHECKFIELDFRM_H__

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
#include <wx/menu.h>
////Header Include End

////Dialog Style Start
#undef checkFieldFrm_STYLE
#define checkFieldFrm_STYLE wxTAB_TRAVERSAL | wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class StartEnd{
    public:
        int table_name;
        int START;
        int END;
        StartEnd(){
            START=1;
            END=0;
        }
};


class checkFieldFrm : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		checkFieldFrm(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("checkField"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = checkFieldFrm_STYLE);
		virtual ~checkFieldFrm();
		//wxString table,current_wd;
		wxString table,table_info,table_name,dname;
		
		//void cwd(wxString);
		void setTableName(wxString);
		int checklongtext(int []);
        
int SHOW,             //current displaying index
    NOW,              //current file stream position
    start,            //declearing for the start of class...
    field_index,
    total_field,
    PPos1,               //previous pos 1
    PREVIOUS,           //Previoud button clicked
    NEXT,               //Next button clicked
    now,               //event after now button..
    index,             // no of field of this table.... read it from checkField()
    IPos,             // initial position
    PPos,             // Previous position  
    CPos,              //current stream position
//    EPos,             // End stream position
    Xpos,
    Ypos,
    data_length,      //current editing data length
    editing_pos,        //position form where editing is to be done
    Edit,               // edit =0,1,2 0->Edit 1->Save 2->AddRecord
    add_record,       //to return CPos to initial
    delete_record,    //to return CPos to initial
    save_record;      //to return CPos to initial  --> may be in the saved record...		
		void Mnudeletetable1002Click(wxCommandEvent& event);
		void Mnulist1003Click(wxCommandEvent& event);
		void Mnueditableview1006Click(wxCommandEvent& event);
		void Mnusubmenuitem21004Click(wxCommandEvent& event);
		void Mnuviewcompletelist1002Click(wxCommandEvent& event);
		StartEnd readTableforlist(int);
		void Mnudeletetable1004Click(wxCommandEvent& event);
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxMenuBar *WxMenuBar1;
		////GUI Control Declaration End
		wxStaticText *lblField[20];
		wxTextCtrl *txtInput[40];
		wxButton *btnAddrecord,*btnNext,*btnDelete,*btnEdit,*btnPrevious,*btnExit,*Button_Next;
//		int index;
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_MNU_VIEW_1001 = 1001,
			ID_MNU_VIEWCOMPLETELIST_1002 = 1002,
			ID_MNU_EDIT_1003 = 1003,
			ID_MNU_DELETETABLE_1004 = 1004,
			
			////GUI Enum Control ID End
        	ID_WXMEMO1 = 1003,
        	ID_WXEDIT1 = 1002,
        	ID_WXSTATICTEXT1 = 1001,
            ID_BTNADDRECORD=500,
            ID_BTNNEXT,
            ID_BTNDELETE,
            ID_BTNEDIT,
            ID_BTNPREVIOUS,
            ID_BTNEXIT,
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
		void makeGUI(wxString text);
		void checkField();
		StartEnd readTable(int index);
		void btnExitClick(wxCommandEvent &event);
		void btnAddrecordClick(wxCommandEvent &event);
		void btnPreviousClick(wxCommandEvent &event);
		void btnNextClick(wxCommandEvent &event);
		void btnDeleteClick(wxCommandEvent &event);
		void btnEditClick(wxCommandEvent &event);
		void Button_NextClick(wxCommandEvent &event);
//		void setTable(wxString table);
        void checkButtons();
		friend void getEdited();
		void getLastPos();
		void addRecord();

//		int getLength(int cpos);
//		friend class table_;

};


#endif
