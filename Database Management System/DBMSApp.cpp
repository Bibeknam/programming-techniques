//---------------------------------------------------------------------------
//
// Name:        DBMSApp.cpp
// Author:      bunkdeath
// Created:     5/25/2010 10:38:10 AM
// Description: 
//
//---------------------------------------------------------------------------

#include "DBMSApp.h"
#include "DBMSFrm.h"
wxString cwd;
IMPLEMENT_APP(DBMSFrmApp)

bool DBMSFrmApp::OnInit()
{
    DBMSFrm* frame = new DBMSFrm(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}
 
int DBMSFrmApp::OnExit()
{
	return 0;
}
