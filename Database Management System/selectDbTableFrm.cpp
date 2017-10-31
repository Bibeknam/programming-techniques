//---------------------------------------------------------------------------
//
// Name:        selectDbTableFrm.cpp
// Author:      deathbunk
// Created:     4/25/2010 9:07:33 PM
// Description: selectDbTableFrm class implementation
//
//---------------------------------------------------------------------------
#include "createFieldFrm.h"

#include "wx/choicdlg.h"
#include "selectDbTableFrm.h"
#include "table.h"
#include "password.h"

#include<fstream>
using namespace std;

#include <wx/textdlg.h>
#include "checkFieldFrm.h"
#include "functions.h"






//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// selectDbTableFrm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(selectDbTableFrm,wxFrame)
	////Manual Code Start
	EVT_TEXT(ID_TXTSELECT,selectDbTableFrm::txtSelectUpdated)
	EVT_BUTTON(ID_BTNSELECT,selectDbTableFrm::btnSelectClick)
	EVT_HYPERLINK(1,selectDbTableFrm::getTables)
	EVT_HYPERLINK(2,selectDbTableFrm::getContens)
	EVT_MENU(ID_MNU_PASSWORD_1004, selectDbTableFrm::Mnupassword1004Click)
	////Manual Code End
	
	EVT_CLOSE(selectDbTableFrm::OnClose)
	EVT_MENU(ID_MNU_ADDTABLE_1007, selectDbTableFrm::Mnuaddtable1007Click)
	EVT_MENU(ID_MNU_DELETE_1008, selectDbTableFrm::Mnudelete1008Click)
	EVT_MENU(ID_MNU_PASSWORD_1004, selectDbTableFrm::Mnupassword1004Click)
	EVT_MENU(ID_MNU_DELETETABLE_1006, selectDbTableFrm::Mnudeletetable1006Click)
END_EVENT_TABLE()
////Event Table End

selectDbTableFrm::selectDbTableFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

selectDbTableFrm::~selectDbTableFrm()
{
}

void selectDbTableFrm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxMenuBar1 = new wxMenuBar();
	wxMenu *ID_MNU_FILE_1001_Mnu_Obj = new wxMenu(0);
	ID_MNU_FILE_1001_Mnu_Obj->Append(ID_MNU_ADDTABLE_1007, wxT("Add Table"), wxT("Add new Table"), wxITEM_NORMAL);
	ID_MNU_FILE_1001_Mnu_Obj->Append(ID_MNU_DELETE_1008, wxT("Delete"), wxT("Delete current Database"), wxITEM_NORMAL);
	WxMenuBar1->Append(ID_MNU_FILE_1001_Mnu_Obj, wxT("&File"));
	
	wxMenu *ID_MNU_EDIT_1003_Mnu_Obj = new wxMenu(0);
	ID_MNU_EDIT_1003_Mnu_Obj->Append(ID_MNU_PASSWORD_1004, wxT("&Password"), wxT(""), wxITEM_NORMAL);
	ID_MNU_EDIT_1003_Mnu_Obj->AppendSeparator();
	ID_MNU_EDIT_1003_Mnu_Obj->Append(ID_MNU_DELETETABLE_1006, wxT("&Delete table\tCtrl+D"), wxT(""), wxITEM_NORMAL);
	WxMenuBar1->Append(ID_MNU_EDIT_1003_Mnu_Obj, wxT("&Edit"));
	SetMenuBar(WxMenuBar1);

	SetTitle(wxT("selectDbTable"));
	SetIcon(wxNullIcon);
	SetSize(8,8,376,392);
	Center();
	
	////GUI Items Creation End
//	WxMenuBar1 = new wxMenuBar();
//	wxMenu *ID_MNU_FILE_1001_Mnu_Obj = new wxMenu(0);
//	WxMenuBar1->Append(ID_MNU_FILE_1001_Mnu_Obj, wxT("&File"));
//	wxMenu *ID_MNU_EDIT_1003_Mnu_Obj = new wxMenu(0);
//	ID_MNU_EDIT_1003_Mnu_Obj->Append(ID_MNU_PASSWORD_1004, wxT("&Password"), wxT(""), wxITEM_NORMAL);
//	WxMenuBar1->Append(ID_MNU_EDIT_1003_Mnu_Obj, wxT("&Edit"));
//	SetMenuBar(WxMenuBar1); 


Dialog_Password =  new wxPasswordEntryDialog( this,wxT(""), wxT("Enter New password"), wxT("") ,wxOK | wxCANCEL | wxCENTRE);
Dialog_Repassword =  new wxPasswordEntryDialog( this,wxT(""), wxT("ReEnter New password"), wxT("") ,wxOK | wxCANCEL | wxCENTRE);
Dialog_Oldpassword =  new wxPasswordEntryDialog( this,wxT(""), wxT("Enter Current password"), wxT("") ,wxOK | wxCANCEL | wxCENTRE);


    txtSelect = new wxTextCtrl(this,ID_TXTSELECT,"",wxPoint(10,10));
    btnSelect = new wxButton(this,ID_BTNSELECT,"&Select",wxPoint(150,10));
    nstart = 0;             //for link destroy

}

void selectDbTableFrm::OnClose(wxCloseEvent& event)
{
    nstart=0;
	Destroy();
}


void selectDbTableFrm::Mnuedit1003Click(wxCommandEvent& event)
{
	// insert your code here
}

void selectDbTableFrm::Mnupassword1004Click(wxCommandEvent& event)
{
	Password();
}

void selectDbTableFrm::cwd(wxString c){
    current_wd=c;
}



/*
 * Mnudeletetable1006Click
 */
void selectDbTableFrm::Mnudeletetable1006Click(wxCommandEvent& event)
{
	// insert your code here

}

/*
 * Mnuaddtable1007Click
 */
void selectDbTableFrm::Mnuaddtable1007Click(wxCommandEvent& event)
{
    if(enablemenu)
    {
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
        
        
    }
    
	// insert your code here
}
}

/*
 * Mnudelete1008Click
 */
void selectDbTableFrm::Mnudelete1008Click(wxCommandEvent& event)
{
        if(enablemenu)
        {
            char *character=new char;
          
            wxString file_input;
            fstream fp2tableinfo;
            fp2tableinfo.open("info.db",ios::in);

            wxString dummy;
            dummy.erase();
    while(1)
    {
        if(fp2tableinfo.eof())
        {
            break;
        }
        else
        {
                    char dum[2];
                
                    fp2tableinfo.read(dum,1);
                    dum[1]='\0';
                    if(dum[0]=='.')
                    {
                   
                        remove(dummy);
                        remove(dummy+".info");
                         dummy.erase();
                        strcpy( dum,"\0");
                    }
                    
	           dummy=dummy+dum;
	            
        }
}
                 
                 
                fp2tableinfo.close(); 
                remove("password.pwd"); 
                remove("info.db"); 
                
                
                      
	
	chdir("..");
	wxString dbname=db[dbno]->GetURL();
     rmdir(dbname);
    fstream fp2dbinfo,fp2db1info;
    fp2dbinfo.open("db.txt",ios::in);
    fp2dbinfo.seekg(0,ios::beg);
   int length=0,integer=0;
    dummy.erase();
  
   while(!fp2dbinfo.eof())
    {
            
           fp2dbinfo.read(character,1);                       // get character from file
            if((integer = ((int)*character-48))<10)
            {  
                length=length*10+integer;
            }
            else if(length)
            {
                
               fp2dbinfo.seekg(-1,ios::cur);
                file_input.erase();
                for(int i=0;i<length;i++)
                {
                    
                 
                    fp2dbinfo.read(character,1);
                    file_input+=character;
              
                }
               
                  if(file_input==dbname)
                    {
                        
                       //wxMessageBox("file_input=dbname",dbname);
                        fp2db1info.open("db1.txt",ios::out);
                        int pos=fp2dbinfo.tellg();
                        fp2dbinfo.seekg(0,ios::end);
                     int epos=fp2dbinfo.tellg();
                        
                        
                     
                        
                       // wxMessageBox(mystring,"tellgpos");
                 
                        fp2dbinfo.seekg(0,ios::beg);
                    int k=0;      
                     while(1)
                    {
                        
                        
                         fp2dbinfo.read(character,1);
                      
                         k++;
                         if(k>pos||k<pos-(length))
                         {
                                   //wxMessageBox("character",character);
                                fp2db1info.write(character,1);
                        }
                
                   wxString mystring = wxString::Format(wxT("%i"),k);
                   //wxMessageBox("value of k",mystring);
                    if (k==epos)
                    {
                               fp2dbinfo.close();
                                      fp2db1info.close();
                                             remove("db.txt");
                                             rename("db1.txt","db.txt");
                    break;
                    
                    }
                }
   
}
 length=0;
}
                     
     

   
} 
}
}
