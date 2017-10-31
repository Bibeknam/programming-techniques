//---------------------------------------------------------------------------
//
// Name:        CreateTableFrm.cpp
// Author:      Administrator
// Created:     20/4/2010 8:22:46
// Description: CreateTableFrm class implementation
//
//---------------------------------------------------------------------------

#include "CreateTableFrm.h"
#include "createFieldFrm.h"
#include<fstream>
using namespace std;

//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// CreateTableFrm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(CreateTableFrm,wxFrame)
	////Manual Code Start
	////Manual Code End
EVT_BUTTON(ID_BUTTON_ADDFIELD,CreateTableFrm::Button_AddFieldClick)
EVT_BUTTON(ID_BUTTON_SAVE,CreateTableFrm::Button_SaveClick)
EVT_BUTTON(ID_BUTTON_EXIT,CreateTableFrm::Button_ExitClick)
	
	EVT_CLOSE(CreateTableFrm::OnClose)
END_EVENT_TABLE()
////Event Table End

CreateTableFrm::CreateTableFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

CreateTableFrm::~CreateTableFrm()
{
    field_creation=0;
    int pos,OK=0;
    fstream check;
    do{
        check.open("db.txt");
        pos=check.tellg();
        if(pos==-1)
            chdir("..");
        else
            OK=1;
    }while(OK);
        
}

void CreateTableFrm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	StaticText_TableName = new wxStaticText(this, ID_STATICTEXT_TABLENAME, wxT("Table Name"), wxPoint(0, 7), wxDefaultSize, 0, wxT("StaticText_TableName"));

	TextBox_TableName = new wxTextCtrl(this, ID_TEXTBOX_TABLENAME, wxT(""), wxPoint(114, 4), wxSize(163, 19), 0, wxDefaultValidator, wxT("TextBox_TableName"));

	SetTitle(wxT("Create Table"));
	SetIcon(wxNullIcon);
	SetSize(8,8,513,334);
	Center();
	
	////GUI Items Creation End
field_creation = 0;
i=80;
global=0; 

    Button_Exit = new wxButton(this, ID_BUTTON_EXIT, wxT("Exit"), wxPoint(380, 10), wxSize(75, 25), 0, wxDefaultValidator, wxT("Button_Exit"));
	Button_Save = new wxButton(this, ID_BUTTON_SAVE, wxT("Save"), wxPoint(300, 10), wxSize(75, 25), 0, wxDefaultValidator, wxT("Button_Save"));
}


void CreateTableFrm::OnClose(wxCloseEvent& event)
{
	Destroy();
}





void CreateTableFrm::Button_SaveClick(wxCommandEvent& event)
{
/*

check for TextBox_TableName, if it is not null, save table,
if TextBox_TableName is null, check for fields,
if TextBox_TableName's value is already present, display that it is already present
and ask to input another or exit.


*/
//    wxString TableName,table_info,FieldName,FieldType;

    TableName<<TextBox_TableName->GetValue();
    table_info = TableName+".info";
    fstream test,info,db;

    int exist=test.tellg();
    test.open(table_info);
    
    if(exist!=-1){
        wxMessageBox("Table already present");
        field_creation=0;
        new_frame=1;
        CreateTableFrm *frm = new CreateTableFrm(NULL);
        frm->Show();
        Destroy();
    }
    else{
        wxString table_name;
        table_name=TextBox_TableName->GetValue();
        db.open("info.db",ios::app|ios::out);
        db.write(table_name,strlen(table_name));
        db.write(".",1);
        }
    
    //      All case finished!!! now ask for more
    if(!new_frame){
        new_frame=0;
        int choice = wxMessageBox("Do you want to create fields now?","Info",wxYES_NO);
        switch(choice){
            case wxYES:
                createFieldFrm *createField = new createFieldFrm(NULL);
                createField->table(TextBox_TableName->GetValue());
                createField->Show();
                Destroy();
                break;
            case wxNO:
                test.open(TableName,ios::out|ios::app);
                test.close();
                int choice = wxMessageBox("Do you want to create new table?","Message",wxYES_NO);
                if(choice==wxYES){
                    Destroy();
                }
                else{
                    Destroy();
                }
                break;
        }
    }
}







void CreateTableFrm::Button_ExitClick(wxCommandEvent& event)
{
    Destroy();
}
    
  
        
 void CreateTableFrm::Button_AddFieldClick(wxCommandEvent& event)
 {

 }
 
void CreateTableFrm::cwd(wxString c){
    current_wd=c;
    chdir(current_wd);
}
