///-----------------------------------------------------------------
///
/// @file      ListViewFrm.cpp
/// @author    Administrator
/// Created:   7/19/2010 1:17:43 PM
/// @section   DESCRIPTION
///            ListViewFrm class implementation
///
///------------------------------------------------------------------

#include "ListViewFrm.h"
#include "checkFieldFrm.h"
//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// ListViewFrm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(ListViewFrm,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(ListViewFrm::OnClose)
END_EVENT_TABLE()
////Event Table End

ListViewFrm::ListViewFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

ListViewFrm::~ListViewFrm()
{
}

void ListViewFrm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	SetTitle(wxT("ListViewFrm"));
	SetIcon(wxNullIcon);
	SetSize(80,21,778,624);
	Center();
	
	////GUI Items Creation End
}

void ListViewFrm::OnClose(wxCloseEvent& event)
{
	Destroy();
}

/*
 * Mnuview1001Click
 */
void ListViewFrm::Mnuview1001Click(wxCommandEvent& event)
{
	// insert your code here
}

/*
 * Mnueditableview1004Click
 */
void ListViewFrm::Mnueditableview1004Click(wxCommandEvent& event)
{
   // checkFieldFrm *check = new checkFieldFrm(this);
	//list->cwd(current_wd);
	//check->Show();
	// insert your code here
	//field->setTableName(table_name);
    //field->Show();
    Destroy();
    
}
