///-----------------------------------------------------------------
///
/// @file      CreateDatabaseFrm.cpp
/// @author    PC_User
/// Created:   4/19/2010 10:52:36 PM
/// @section   DESCRIPTION
///            CreateDatabaseFrm class implementation
///
///------------------------------------------------------------------
#include "CreateTableFrm.h"
#include "CreateDatabaseFrm.h"
#include "createFieldFrm.h"
#include "DBMSFrm.h"
#include<fstream>
#include<cstring>
using namespace std;



//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// CreateDatabaseFrm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(CreateDatabaseFrm,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(CreateDatabaseFrm::OnClose)
	EVT_BUTTON(ID_BUTTON_CANCEL,CreateDatabaseFrm::Button_CancelClick)
	EVT_BUTTON(ID_BUTTON_SAVEDATABASE,CreateDatabaseFrm::Button_SaveClick)
END_EVENT_TABLE()
////Event Table End

CreateDatabaseFrm::CreateDatabaseFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

CreateDatabaseFrm::~CreateDatabaseFrm()
{
//    DBMSFrm->Show();
}

void CreateDatabaseFrm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	Button_Cancel = new wxButton(this, ID_BUTTON_CANCEL, wxT("Cancel"), wxPoint(186, 301), wxSize(86, 29), 0, wxDefaultValidator, wxT("Button_Cancel"));

	Button_SaveDatabase = new wxButton(this, ID_BUTTON_SAVEDATABASE, wxT("Save"), wxPoint(27, 299), wxSize(86, 29), 0, wxDefaultValidator, wxT("Button_SaveDatabase"));

	TextBox_RePassword = new wxTextCtrl(this, ID_TEXTBOX_REPASSWORD, wxT(""), wxPoint(150, 209), wxSize(140, 22), wxTE_PASSWORD, wxDefaultValidator, wxT("TextBox_RePassword"));

	TextBox_Password = new wxTextCtrl(this, ID_TEXTBOX_PASSWORD, wxT(""), wxPoint(151, 129), wxSize(140, 22), wxTE_PASSWORD, wxDefaultValidator, wxT("TextBox_Password"));

	TextBox_DatabaseName = new wxTextCtrl(this, ID_TEXTBOX_DATABASENAME, wxT(""), wxPoint(127, 13), wxSize(173, 22), 0, wxDefaultValidator, wxT("TextBox_DatabaseName"));

	StaticText_RePassword = new wxStaticText(this, ID_STATICTEXT_REPASSWORD, wxT("Re-Password"), wxPoint(20, 218), wxDefaultSize, 0, wxT("StaticText_RePassword"));

	StaticText_Password = new wxStaticText(this, ID_STATICTEXT_PASSWORD, wxT("Password"), wxPoint(14, 135), wxDefaultSize, 0, wxT("StaticText_Password"));

	StaticText_Optional = new wxStaticText(this, ID_STATICTEXT_OPTIONAL, wxT("(*Optional)"), wxPoint(14, 81), wxDefaultSize, 0, wxT("StaticText_Optional"));

	StaticBox_Security = new wxStaticBox(this, ID_STATICBOX_SECURITY, wxT("Security Option"), wxPoint(3, 62), wxSize(330, 232));

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, wxT("Database Name"), wxPoint(5, 14), wxDefaultSize, 0, wxT("WxStaticText1"));

	SetTitle(wxT("Create Database"));
	SetIcon(wxNullIcon);
	SetSize(8,8,376,384);
	Center();

	
	////GUI Items Creation End
}

void CreateDatabaseFrm::OnClose(wxCloseEvent& event)
{
	Destroy();
}

void CreateDatabaseFrm::Button_SaveClick(wxCommandEvent& event)
{
  
	wxString dname,password,repassword;
	dname<<TextBox_DatabaseName->GetValue();
	password<<TextBox_Password->GetValue();
	repassword<<TextBox_RePassword->GetValue();
    fstream fpinfo;

  
    fpinfo.open("db.txt",ios::out|ios::app);
	if ((password!="\0" )&&(password!=repassword))
        wxMessageBox("Passwords do not match!","Message",wxOK);  
    else if (password==repassword){
        if (mkdir(dname)==-1){
             wxMessageBox("Database already exists","Message",wxOK);
             TextBox_DatabaseName->SetValue("");
        }
        else{
            wxString length;
            length.Printf("%d",strlen(dname));
            fpinfo.write(length,strlen(length));  
            fpinfo.write(dname,strlen(dname));
            length.Printf("%d",strlen(password));
            if(password!=""){
                chdir(dname);
                out=1;
                fstream pwd;
                pwd.open("password.pwd",ios::out|ios::app);
                pwd.write(password,strlen(password));  
            }
            if(password!="\0")
                wxMessageBox("database and Password saved","Message",wxOK);
            else 
                wxMessageBox("database saved","Message",wxOK);
            chdir(dname);
            out=1;
            wxString table_name;
            table_name=wxGetTextFromUser("Enter table name","DBMS");
            fstream db;
            db.open("info.db",ios::app|ios::out);
            if(table_name!=""){
                db.write(table_name,strlen(table_name));
                db.write(".",1);
                createFieldFrm *field = new createFieldFrm(NULL);
                field->cwdDbTable(current_wd,dname,table_name);
//                field->db(dname);
//                field->table(table_name);
                field->Show();
                Destroy();
            }
            else{
                chdir(current_wd);
                TextBox_DatabaseName->SetValue("");
            }
        }
    }
    fpinfo.close();
    fpinfo.close();
}

void CreateDatabaseFrm::Button_CancelClick(wxCommandEvent& event)
{
	this->Destroy();
}

void CreateDatabaseFrm::cwd(wxString c){
    current_wd=c;
//	chdir(current_wd);
}
