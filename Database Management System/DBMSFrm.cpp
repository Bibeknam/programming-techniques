///-----------------------------------------------------------------
///
/// @file      DBMSFrm.cpp
/// @author    bunkdeath
/// Created:   5/25/2010 10:38:11 AM
/// @section   DESCRIPTION
///            DBMSFrm class implementation
///
///------------------------------------------------------------------

#include "DBMSFrm.h"
#include"CreateDatabaseFrm.h"
#include "selectDbTableFrm.h"
#include<wx/dir.h>
//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// DBMSFrm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(DBMSFrm,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(DBMSFrm::OnClose)
	EVT_BUTTON(ID_BTNSELECT,DBMSFrm::btnSelectClick)
	EVT_BUTTON(ID_BTNCREATE,DBMSFrm::btnCreateClick)
END_EVENT_TABLE()
////Event Table End

DBMSFrm::DBMSFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

DBMSFrm::~DBMSFrm()
{
}

void DBMSFrm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	btnSelect = new wxButton(this, ID_BTNSELECT, wxT("Select Database"), wxPoint(66, 102), wxSize(130, 25), 0, wxDefaultValidator, wxT("btnSelect"));

	btnCreate = new wxButton(this, ID_BTNCREATE, wxT("Create Database"), wxPoint(63, 56), wxSize(136, 25), 0, wxDefaultValidator, wxT("btnCreate"));

	SetTitle(wxT("DBMS"));
	SetIcon(wxNullIcon);
	SetSize(8,8,320,334);
	Center();
	
	////GUI Items Creation End
	
	current_wd=wxGetCwd();
}

void DBMSFrm::OnClose(wxCloseEvent& event)
{
	Destroy();
}



void DBMSFrm::btnCreateClick(wxCommandEvent& event)
{
    //current_wd = wxGetCwd();
	chdir(current_wd);
	CreateDatabaseFrm *create = new CreateDatabaseFrm(this);
	create->cwd(current_wd);
	create->Show();
//	this->Show(false);
//	this->Hide();
}



void DBMSFrm::btnSelectClick(wxCommandEvent& event)
{
    //current_wd = wxGetCwd();
	chdir(current_wd);
	selectDbTableFrm *select = new selectDbTableFrm(this);
	select->cwd(current_wd);
	select->Show();
}

