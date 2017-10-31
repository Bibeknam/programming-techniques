///-----------------------------------------------------------------
///
/// @file      CreateFieldsFrm.h
/// @author    PC_User
/// Created:   5/9/2010 10:27:54 PM
/// @section   DESCRIPTION
///            CreateFieldsFrm class declaration
///
///------------------------------------------------------------------

#ifndef __CREATEFIELDSFRM_H__
#define __CREATEFIELDSFRM_H__

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
#undef CreateFieldsFrm_STYLE
#define CreateFieldsFrm_STYLE wxTAB_TRAVERSAL | wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class createFieldFrm : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		createFieldFrm(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Create Fields"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = CreateFieldsFrm_STYLE);
		virtual ~createFieldFrm();
		void Button_ExitClick(wxCommandEvent& event);
		void Button_AddFieldClick(wxCommandEvent& event);
		void ComboBox_FieldTypeSelected(wxCommandEvent& event);

        void table(wxString);
		void showFields();
		void save();
		int check();
		void cwdDbTable(wxString,wxString,wxString);
//		void db(wxString);
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		////GUI Control Declaration End
	
	
	    wxString table_name,table_design,current_wd,dname;


		wxButton *Button_AddField;
		wxButton *Button_Exit;
		wxSpinCtrl *SpinCtrl_FieldLength;
		wxComboBox *ComboBox_FieldType;
		wxTextCtrl *Textbox_FieldName;
		wxStaticText *StaticText_FieldLength;
		wxStaticText *StaticText_FieldType;
		wxStaticText *StaticText_FieldName;
		
		int i;
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			////GUI Enum Control ID End
			
            
            
			ID_SPINCTRL_FIELDLENGTH = 1009,
			ID_COMBOBOX_FIELDTYPE = 1008,
			ID_STATICTEXT_FIELDLENGTH = 1007,
            ID_STATICTEXT_FIELDTYPE = 1006,
			ID_STATICTEXT_FIELDNAME = 1005,
			ID_TEXTBOX_FIELDNAME = 1004,
			ID_BUTTON_EXIT = 1003,
		
			ID_BUTTON_ADDFIELD = 1001,
         //   ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
	      
		
		
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif
