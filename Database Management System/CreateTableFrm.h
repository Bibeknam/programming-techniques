//---------------------------------------------------------------------------
//
// Name:        CreateTableFrm.h
// Author:      Administrator
// Created:     20/4/2010 8:22:46
// Description: CreateTableFrm class declaration
//
//---------------------------------------------------------------------------

#ifndef __CREATETABLEFRM_h__
#define __CREATETABLEFRM_h__

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
#include <wx/stattext.h>
#include <wx/textctrl.h>

////Header Include End
#include<wx/spinctrl.h>

////Dialog Style Start
#undef CreateTableFrm_STYLE
#define CreateTableFrm_STYLE wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class CreateTableFrm : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		CreateTableFrm(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Create Table"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = CreateTableFrm_STYLE);
		virtual ~CreateTableFrm();
		
		void Button_SaveClick(wxCommandEvent& event);
		void Button_AddFieldClick(wxCommandEvent& event);
		void Button_ExitClick(wxCommandEvent& event);
        void createField(wxString table_name);
        void cwd(wxString);
        int field_creation,
            create_table,
            i,
            global,
            new_frame;
        		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxStaticText *StaticText_TableName;
		wxTextCtrl *TextBox_TableName;
		////GUI Control Declaration End
		wxButton *Button_Exit;
		wxButton *Button_AddField;
		wxButton *Button_Save;
		wxSpinCtrl *SpinCtrl_FieldLength;
		wxComboBox *ComboBox_FieldType;
		wxTextCtrl *Textbox_FieldName;
		wxStaticText *StaticText_FieldLength;
		wxStaticText *StaticText_FieldType;
		wxStaticText *StaticText_FieldName;
	   wxString TableName,table_info,FieldName,FieldType,current_wd;
		
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			
            ////GUI Enum Control ID End
            ID_BUTTON_EXIT = 1011,
			ID_BUTTON_ADDFIELD = 1010,
			ID_BUTTON_SAVE = 1009,
			ID_SPINCTRL_FIELDLENGTH = 1008,
			ID_COMBOBOX_FIELDTYPE = 1007,
			ID_TEXTBOX_FIELDNAME = 1006,
			
			ID_STATICTEXT_FIELDLENGTH = 1004,
			ID_STATICTEXT_FIELDTYPE = 1003,
			ID_STATICTEXT_FIELDNAME = 1005,
			ID_STATICTEXT_TABLENAME = 1002,
			ID_TEXTBOX_TABLENAME = 1001,
			
			
			
		//	ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

//enum FieldType{Integer,Decimal,Text,LongText};
class TableStore
{
    char FieldName[20];
char  FieldType[14];

    int FieldLength;
    public:
        TableStore(){}
        TableStore(wxString FieldName1,wxString FieldType1,int FieldLength1)
        {
            strcpy(FieldName,FieldName1);
            strcpy(FieldType,FieldType1);
    FieldLength=FieldLength1;
       
        }
    };
  
struct DesignTableTable
{
   
    char name[20];
    int snum;
};



  

#endif
