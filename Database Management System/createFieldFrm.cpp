///-----------------------------------------------------------------
///
/// @file      createFieldFrm.cpp
/// @author    PC_User
/// Created:   5/9/2010 10:27:54 PM
/// @section   DESCRIPTION
///            createFieldFrm class implementation
///
///------------------------------------------------------------------
#include<wx/string.h>
#include "createFieldFrm.h"
#include "checkFieldFrm.h"
#include<wx/spinctrl.h>
#include<fstream>

using namespace std;
//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// createFieldFrm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(createFieldFrm,wxFrame)
	////Manual Code Start
	EVT_BUTTON(ID_BUTTON_ADDFIELD,createFieldFrm::Button_AddFieldClick)
	EVT_BUTTON(ID_BUTTON_EXIT,createFieldFrm::Button_ExitClick)
	EVT_COMBOBOX(ID_COMBOBOX_FIELDTYPE,createFieldFrm::ComboBox_FieldTypeSelected)
	////Manual Code End
	
	EVT_CLOSE(createFieldFrm::OnClose)
END_EVENT_TABLE()
////Event Table End

createFieldFrm::createFieldFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

createFieldFrm::~createFieldFrm()
{
}

void createFieldFrm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	SetTitle(wxT("Create Fields"));
	SetIcon(wxNullIcon);
	SetSize(-1,-1,620,242);
	Center();
	
	////GUI Items Creation End
	i=80;
	showFields();
}

void createFieldFrm::OnClose(wxCloseEvent& event)
{
	Destroy();
}


void createFieldFrm::Button_ExitClick(wxCommandEvent& event)   // save and add
{
    int checkvalue=check();
    if (checkvalue==0)
{   
    save();
    int choice = wxMessageBox("Do you want to add new table?","Message",wxYES_NO);
    if(choice==wxYES){
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
                Destroy();}
                
        else
        Destroy();
        //checkFieldFrm *check = new checkFieldFrm(NULL);
        //check->setTableName(table_name);
        //check->Show();

}
    else{
        Destroy();
    }
    
}
    else if (checkvalue==1)
        wxMessageBox("Cannot Save\nPlease enter correct Field Name\n Field name cannot contain space,.","Message",ERROR);
    else if (checkvalue==2)
        wxMessageBox("Cannot Save\nPlease select Field Type from the List.","Message",ERROR);
    else if (checkvalue==4)
        wxMessageBox("Cannot Save\nTable name already exists","Message",ERROR);
    else 
        wxMessageBox("Cannot Save\nPlease enter correct Field Length\n Minimun Field Length is 1","Message",ERROR);
    
}

void createFieldFrm::ComboBox_FieldTypeSelected(wxCommandEvent& event )
{
    wxString FieldType;
     FieldType<<ComboBox_FieldType->GetString(ComboBox_FieldType->GetSelection());
if(FieldType==wxT("LONGTEXT"))
          SpinCtrl_FieldLength->Disable();
else
  SpinCtrl_FieldLength->Enable();

}

void createFieldFrm::Button_AddFieldClick(wxCommandEvent& event)   //save and add
{
    int checkvalue=check();
    if (checkvalue==0)
{   
    save();
    showFields();
    
}
    else if (checkvalue==1)
        wxMessageBox("Cannot Save\nPlease enter correct Field Name\n Field name cannot contain space,.","Message",ERROR);
    else if (checkvalue==2)
        wxMessageBox("Cannot Save\nPlease select Field Type from the List.","Message",ERROR);
      else if (checkvalue==4){
        wxMessageBox("Cannot Save\nField name already exists","Message",ERROR);
        Textbox_FieldName->SetValue("");
        ComboBox_FieldType->SetSelection(0);
        SpinCtrl_FieldLength->SetValue(0);
    }
      
    else 
        wxMessageBox("Cannot Save\nPlease enter correct Field Length\n Minimun Field Length is 1","Message",ERROR);
    
    
    
    
    
}


void createFieldFrm::showFields(){
    StaticText_FieldName = new wxStaticText(this, ID_STATICTEXT_FIELDNAME, wxT("Field Name"), wxPoint(11, 60), wxDefaultSize, 0, wxT("StaticText_FieldName"));
    Textbox_FieldName = new wxTextCtrl(this, ID_TEXTBOX_FIELDNAME, wxT(""), wxPoint(2, i), wxSize(121, 19), 0, wxDefaultValidator, wxT("Textbox_FieldName"));

    StaticText_FieldType = new wxStaticText(this, ID_STATICTEXT_FIELDTYPE, wxT("Field Type"), wxPoint(170, 60), wxDefaultSize, 0, wxT("StaticText_FieldType"));
    wxArrayString arrayStringFor_ComboBox_FieldType;
    arrayStringFor_ComboBox_FieldType.Add(wxT("INT"));
    arrayStringFor_ComboBox_FieldType.Add(wxT("CHAR"));
    arrayStringFor_ComboBox_FieldType.Add(wxT("LONGTEXT"));
    ComboBox_FieldType = new wxComboBox(this, ID_COMBOBOX_FIELDTYPE, wxT(""), wxPoint(141, i), wxSize(145, 21), arrayStringFor_ComboBox_FieldType, 2, wxDefaultValidator, wxT("ComboBox_FieldType"));

    StaticText_FieldLength = new wxStaticText(this, ID_STATICTEXT_FIELDLENGTH, wxT("Field Length"), wxPoint(308, 60), wxDefaultSize, 0, wxT("StaticText_FieldLength"));
    SpinCtrl_FieldLength= new wxSpinCtrl(this, ID_SPINCTRL_FIELDLENGTH, wxT("0"), wxPoint(312, i), wxSize(51, 22), wxSP_ARROW_KEYS, 0, 100, 1);
    Button_AddField = new wxButton(this, ID_BUTTON_ADDFIELD, wxT("Save and Add"), wxPoint(410, i), wxSize(75, 25), 0, wxDefaultValidator, wxT("Button_AddField"));
    Button_Exit = new wxButton(this, ID_BUTTON_EXIT, wxT("Save and Exit"), wxPoint(500, i), wxSize(75, 25), 0, wxDefaultValidator, wxT("Button_Exit"));
    i=i+30;
}





int createFieldFrm::check()
{
    int pos;
    pos=0;
    wxString FieldName,FieldType,FieldLength,mystring;
    
    FieldName<<Textbox_FieldName->GetValue();
    FieldType<<ComboBox_FieldType->GetString(ComboBox_FieldType->GetSelection());
    FieldLength<<SpinCtrl_FieldLength->GetValue();
    int length=FieldName.Len();
    int cint=0,check=0;
    mystring << cint;

   
        
     if(FieldType==wxT("LONGTEXT"))
     FieldLength=wxT("5");
    if (FieldLength==mystring)
            check=3;    
    if(FieldType==wxT(""))
            check=2;
            
    fstream fp2tabledesign;
    fp2tabledesign.open(table_design,ios::in);
    if (fp2tabledesign)
    {
         char dum[2];
                wxString dummy;
                dummy.erase();
    while(1)
    {
        if(fp2tabledesign.eof()){
            break;
        }
        else{
                    fp2tabledesign.read(dum,1);
                    dummy=dummy+dum;
                    if(dum[0]=='\n'){
                        pos=0;
                    }
                    else if(dum[0]=='.')
                    {
                        pos++;
                        if(pos==2){
                            if (dummy==(FieldName+"."))
                            {
                                check=4;
                                return check;
                            }
                        }
                        dummy.erase();
                   }
        }    
    }
}           
                
  for (int i=0;i<length;i++)
            {
                wxChar a;
                a=FieldName.GetChar(i);
                if (a=='.'||a==' '|| a=='#')
                {
                       check=1;
                        break;
                }
            }
    
        return check;
}
        
    
void createFieldFrm::save()
{
        wxString FieldName,FieldType,FieldLength,mystring;
        fstream info;
        int cint=0;
        int check=1;
        mystring << cint;
        FieldName<<Textbox_FieldName->GetValue();
        FieldType<<ComboBox_FieldType->GetString(ComboBox_FieldType->GetSelection());
        if(FieldType!=wxT("LONGTEXT"))
        FieldLength<<SpinCtrl_FieldLength->GetValue();

        info.open(table_design,ios::out|ios::app);// save in table_name.info
        info.write("member",6);
        info.write(".",1);
        info.write(FieldName,strlen(FieldName));
        info.write(".",1);
        info.write(FieldType,strlen(FieldType));
        if(FieldType!=wxT("LONGTEXT"))
        {
      
         info.write(".",1);
        info.write(FieldLength,strlen(FieldLength));
    }
        info.write("\n",1);
        info.close();
        delete(Button_AddField);
        delete(Button_Exit);

        fstream table;
        table.open(table_name,ios::out);
}


void createFieldFrm::cwdDbTable(wxString c,wxString d,wxString t){
    current_wd=c;
    table_name=t;
    dname=d;
    table_design=table_name+".info";
    chdir(current_wd);
    chdir(dname);
}
//
void createFieldFrm::table(wxString tbl_name){
    table_name=tbl_name;
    table_design=table_name+".info";
}  

