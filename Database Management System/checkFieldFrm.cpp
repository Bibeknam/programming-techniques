///-----------------------------------------------------------------
///
/// @file      checkFieldFrm.cpp
/// @author    bunkdeath
/// Created:   4/21/2010 10:03:44 PM
/// @section   DESCRIPTION
///            checkFieldFrm class implementation
///
///------------------------------------------------------------------
#include "ListViewFrm.h"
#include "checkFieldFrm.h"
#include "selectDbTableFrm.h"
#include"table.h"
#include<iostream>
#include<fstream>
using namespace std;

wxString a;
wxString startMsg;
StartEnd check;
int EPos,
    end_pos;           //end position as whole index

wxString table_name;
int make_gui=0;                 // to create GUI of selected table


//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// checkFieldFrm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(checkFieldFrm,wxFrame)
	////Manual Code Start
	EVT_BUTTON(ID_BTNPREVIOUS,checkFieldFrm::btnPreviousClick)
	EVT_BUTTON(ID_BTNEDIT,checkFieldFrm::btnEditClick)
	EVT_BUTTON(ID_BTNDELETE,checkFieldFrm::btnDeleteClick)
	EVT_BUTTON(ID_BTNNEXT,checkFieldFrm::btnNextClick)
	EVT_BUTTON(ID_BTNADDRECORD,checkFieldFrm::btnAddrecordClick)
	EVT_BUTTON(ID_BTNEXIT,checkFieldFrm::btnExitClick)
	EVT_BUTTON(1,checkFieldFrm::Button_NextClick)
	////Manual Code End
	
	EVT_CLOSE(checkFieldFrm::OnClose)
	EVT_MENU(ID_MNU_VIEWCOMPLETELIST_1002, checkFieldFrm::Mnuviewcompletelist1002Click)
	EVT_MENU(ID_MNU_DELETETABLE_1004, checkFieldFrm::Mnudeletetable1004Click)
END_EVENT_TABLE()
////Event Table End

checkFieldFrm::checkFieldFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

checkFieldFrm::~checkFieldFrm(){}

void checkFieldFrm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxMenuBar1 = new wxMenuBar();
	wxMenu *ID_MNU_VIEW_1001_Mnu_Obj = new wxMenu(0);
	ID_MNU_VIEW_1001_Mnu_Obj->Append(ID_MNU_VIEWCOMPLETELIST_1002, wxT("List"), wxT("View Complete list of the entries for this table"), wxITEM_NORMAL);
	WxMenuBar1->Append(ID_MNU_VIEW_1001_Mnu_Obj, wxT("View"));
	
	wxMenu *ID_MNU_EDIT_1003_Mnu_Obj = new wxMenu(0);
	ID_MNU_EDIT_1003_Mnu_Obj->Append(ID_MNU_DELETETABLE_1004, wxT("Delete Table"), wxT("Delete This Table"), wxITEM_NORMAL);
	WxMenuBar1->Append(ID_MNU_EDIT_1003_Mnu_Obj, wxT("Edit"));
	SetMenuBar(WxMenuBar1);

	SetTitle(wxT("checkField"));
	SetIcon(wxNullIcon);
	SetSize(21,-13,519,350);
	Center();
	
	////GUI Items Creation End
	Edit=0,
    end_pos=0,
    SHOW=0,
    NEXT=0,
    now=0,
    EPos=0,
    start=1,            //declearing for the start of class...
    field_index=0,
    total_field=0,
    index=0,             // no of field of this table.... read it from checkField()
    Xpos=30,
    Ypos=10,
    data_length=0,      //current editing data length
    add_record=0,       //to return CPos to initial
    delete_record=0,    //to return CPos to initial
    save_record=0;      //to return CPos to initial  --> may be in the saved record...		

    
    

//    table_name=((selectDbTableFrm*)GetParent())->getTableName();


//    getLastPos();
//	checkField();
//###################################################################
	SHOW=1;                                                       //
    NOW=0;
//###################################################################
//    getLastPos();
//	checkField();
//  	readTable(index);


}

void checkFieldFrm::OnClose(wxCloseEvent& event)
{
	Destroy();
}





void checkFieldFrm::checkField()
{
    char *character = new char;
    wxString text,table_design;
    Xpos=30;
    Ypos=10;


    ifstream file;
//    file.open("info");
    table_design=table_name+".info";
    file.open(table_design);
    int is = file.tellg();
    if(is==-1){
        wxMessageBox("file absent");
    }
    else{
        while(!file.eof()){
            file.read(character,1);
            if(!strcmp(character,".")){// && make_gui){
                    makeGUI(text);
                    field_index++;
                    text.Empty();
            }

            else if(!(strcmp(character,"\n")) || file.eof()){// && make_gui){                      // Search for ENTER
                    makeGUI(text);
                    field_index=0;
                    text.Empty();
            }
            else{
                text+=character;
            }
        }
    }
    file.close();


	btnPrevious = new wxButton(this, ID_BTNPREVIOUS, wxT("&Previous"),wxPoint(Xpos-=10, Ypos), wxSize(53, 25), 0, wxDefaultValidator, wxT("btnPrevious"));
    btnPrevious->Enable(false);

	btnEdit = new wxButton(this, ID_BTNEDIT, wxT("&Edit"), wxPoint(Xpos+=56, Ypos), wxSize(46, 24), 0, wxDefaultValidator, wxT("btnEdit"));

	btnDelete = new wxButton(this, ID_BTNDELETE, wxT("&Delete"), wxPoint(Xpos+=50, Ypos), wxSize(49, 24), 0, wxDefaultValidator, wxT("btnDelete"));

    btnNext = new wxButton(this, ID_BTNNEXT, wxT("&Next"), wxPoint(Xpos+=55, Ypos), wxSize(61, 24), 0, wxDefaultValidator, wxT("btnNext"));

	btnAddrecord = new wxButton(this, ID_BTNADDRECORD, wxT("&Add record"), wxPoint(Xpos=40, Ypos+=34), wxSize(75, 25), 0, wxDefaultValidator, wxT("btnAddrecord"));

	
	btnExit = new wxButton(this,ID_BTNEXIT,wxT("E&xit"),wxPoint(Xpos+=80,Ypos),wxSize(75,25),0,wxDefaultValidator,wxT("btnExit"));






}







void checkFieldFrm::makeGUI(wxString text){

    switch(field_index){
        case 1:
            index++;
            lblField[index] = new wxStaticText(this, ID_WXSTATICTEXT1, text, wxPoint(Xpos,Ypos), wxDefaultSize, 0, wxT("WxStaticText1"));                
            Xpos +=60;
            break;
        case 2:
            if(text=="CHAR" || text=="INT"){
                txtInput[index] = new wxTextCtrl(this, ID_WXEDIT1, wxT(""), wxPoint(Xpos,Ypos), wxSize(121, 19), 0, wxDefaultValidator);
                a.Printf("%d",index);
                txtInput[index]->SetValue(a);
                txtInput[index]->Enable(false);
                Ypos+=30;
                Xpos=30;
            }
            else{
            	txtInput[index] = new wxTextCtrl(this, ID_WXMEMO1, wxT(""), wxPoint(Xpos, Ypos), wxSize(185, 89), wxTE_MULTILINE, wxDefaultValidator, wxT("WxMemo1"));
                a.Printf("%d",index);
                txtInput[index]->SetValue(a);
            	txtInput[index]->SetMaxLength(0);
            	txtInput[index]->SetFocus();
            	txtInput[index]->SetInsertionPointEnd();
            	txtInput[index]->Enable(false);
            	Ypos+=100;
            	Xpos=30;
            }

            break;
        case 3:
            int length=0,integer,i=0;
            while(text[i]!='\0'){
                if((integer = ((int)text[i]-48))<10)    //checking for number
                    length=length*10+integer;
                i++;
            }
                txtInput[index]->SetMaxLength(length);
                break;
        }
}








  /////////////////////////////////////////////////////////
 ////// remove re occuring of last character repeat///////
/////////////////////////////////////////////////////////

void checkFieldFrm::btnEditClick(wxCommandEvent &event){
//wxString("asdf");
    fstream file,buffer;
    wxString field_data,take,z;
    switch(Edit){                   //EDIT
        case 0:
            for(int i=1;i<=index;i++)
                txtInput[i]->Enable(true);
            btnEdit->SetLabel("&Save");
            Edit=1;
checkButtons();
            break;
        case 1:                     // SAVE
            save_record=1;
            char *character = new char;
            btnEdit->SetLabel("&Edit");
            Edit=0;
            file.open(table_name,/*ios::app|ios::out|*/ios::in);
            buffer.open("buffer.txt",ios::out);
            take.erase();
                for(int i=0;i<=editing_pos;i++){
                    file.read(character,1);
                    take+=character;
                }
                if(!editing_pos){//==""){
                    take="1";
                }
                buffer.write(take,strlen(take));
            buffer.write(">",1);
            for(int i=1;i<=index;i++){
                wxString len;
                field_data=txtInput[i]->GetValue();
                len.Printf("%d",strlen(field_data));
                buffer.write(len,strlen(len));
                buffer.write("<",1);
                buffer.write(field_data,strlen(field_data));
                txtInput[i]->Enable(false);
            }
            take.erase();
            for(int i=0;i<(data_length-1);i++)
                file.read(character,1);           //blank read previous data
              while(1){
                file.read(character,1);
                if(file.eof())
                    break;
                else
                    take+=character;
            }

            buffer.write(take,strlen(take));
            file.close();
            buffer.close();
            unlink(table_name);                            // replace file name
            rename("buffer.txt",table_name);               //replace file name

            Edit=0;
//            file.close();
checkButtons();
            break;
        case 2:                 // AddRecord
            save_record=1;
            add_record=0;
            btnEdit->SetLabel("&Edit");
            Edit=0;

            fstream file;
            file.open(table_name,ios::app|ios::out);
            int i=file.tellg();
            if(i==-1)
                wxMessageBox("File not");
            take.Printf("%d",++end_pos);
            EPos++;
            file.write(take,strlen(take));
            file.write(">",1);
            for(int i=1;i<=index;i++){
                field_data=txtInput[i]->GetValue();
                take.Printf("%d",strlen(field_data));
                file.write(take,strlen(take));
                file.write("<",1);
                file.write(field_data,strlen(field_data));
                txtInput[i]->Enable(false);
            }
            file.close();
            ++EPos;
            SHOW=EPos;
checkButtons();
            readTable(index);
            break;
    }

}











void checkFieldFrm::btnExitClick(wxCommandEvent &event){
    Destroy();
}









StartEnd checkFieldFrm::readTable(int index){
//    if(EPos==1){
//        btnPrevious->Enable(false);
//    }
//    else{
//        btnPrevious->Enable(true);
//    }
//    if(SHOW==EPos){
//        btnNext->Enable(false);
//    }
//    else{
//        btnNext->Enable(true);
//    }

checkButtons();

    NOW=0;
    StartEnd asdf;
    ifstream file;
    file.open (table_name);
    data_length=0;
    int ap=file.tellg();
    if(ap==-1){
        int choice;
        choice=wxMessageBox("Table not present\nDo you want to create?","Message",wxYES_NO);
        switch(choice){
            case wxYES:
                Edit=2;
                addRecord();
                break;
            case wxNO:
                Destroy();
                break;
        }
        return asdf;
    }
    int integer,length=0,field_index=1;//file_size=is.tellg();data_test,
    char *character=new char;
    wxString fileInput,test,total_data;
    editing_pos=file.tellg();
    total_data.erase();
    while (!file.eof() && field_index<=index)//&&(Fpos+1)!=file_size)          //is.good() loop while e-o-f is reached
    {
        test.erase();
        file.read(character,1);                   // get character from file
        data_length++;
        test+=character;
        total_data+=character;
        if((integer = ((int)*character-48))<10){    //checking for number
            length=length*10+integer;
        }
        else if(!strcmp(character,">")){
            NOW++;
            if(save_record || add_record || delete_record || start){
                save_record=add_record=delete_record=start=0;
                IPos=PPos=CPos=length;
            }
            CPos=length;
            PPos1=length;
            length=0;
        }
        else if(!strcmp(character,"<")){
            fileInput.erase();
            for(int i=0;i<length;i++){
                file.read(character,1);
                total_data+=character;
                fileInput+=character;
            }
            if(file.peek()=='\n'){
                file.seekg(ios::beg);
                btnNext->Enable(false);
            }
            if(NOW==SHOW){
            txtInput[field_index]->SetValue(fileInput);
            field_index++;
          }
          else{
            total_data.erase();
            editing_pos=file.tellg();
			editing_pos--;
        }
        length=0;
        data_length=strlen(total_data);         //TOTAL LENGTH OF CURRENT DATA
        }                                       //else
    }                                           //while
    if(file.eof()){
        check.START=0;
        check.END=1;
    }
    else{
        if(CPos==IPos)
            check.START=1;
        else
            check.START=0;
        check.END=0;
    }
    file.close();


if(CPos==IPos)
    PPos=CPos;
    delete character;
    return check;
}










void checkFieldFrm::btnNextClick(wxCommandEvent &event){
    wxString a;
    NEXT=1;
    if(SHOW!=EPos){
        SHOW++;
        btnPrevious->Enable(true);
        ifstream is;
        is.open(table_name);
        check = readTable(index);
    }

checkButtons();
//    if(SHOW==EPos){
//        btnNext->Enable(false);
//        ifstream is;
//        is.open(table_name);
//        CPos=IPos;
//        PPos=IPos;
//        check=readTable(index);
//    }
}


void checkFieldFrm::Button_NextClick(wxCommandEvent &event)
{
    
}
    





void checkFieldFrm::btnPreviousClick(wxCommandEvent &event){
    PREVIOUS=1;
    wxString a;
    if(SHOW!=1){
        SHOW--;
        ifstream is;
        is.open(table_name);
        check = readTable(index);
        btnNext->Enable(true);
    }

checkButtons();
//    if(SHOW==1){
//        btnPrevious->Enable(false);
//        PREVIOUS=0;
//    }
}







void checkFieldFrm::btnDeleteClick(wxCommandEvent &event){
    fstream file,buffer;
    wxString take;
    char *character = new char;
    file.open(table_name,ios::in);
    buffer.open("buffer.txt",ios::out);
    take.erase();
//    wxString a;
//    a.Printf("%d",editing_pos);
//    wxMessageBox(a);
    if(editing_pos){
        for(int i=0;i<=editing_pos;i++){
            file.read(character,1);
            take+=character;
        }
    }
        buffer.write(take,strlen(take));
    take.erase();
//    wxString t;
//    t.Printf("%d",data_length);
//    wxMessageBox(t);
    for(int i=0;i<(data_length);i++){
        file.read(character,1);           //blank read previous data
        take+=character;
    }
//    wxMessageBox(take);
    take.erase();
    while(1){
        file.read(character,1);
        if(file.eof())
            break;
        else
            take+=character;
    }
    buffer.write(take,strlen(take));
    file.close();
    buffer.close();
    unlink(table_name);                            // replace file name
    rename("buffer.txt",table_name);               //replace file name
    file.open(table_name,ios::in);
    btnEdit->SetLabel("&Edit");
    Edit=0;
    file.close();
    delete_record=1;
    SHOW--;
    EPos--;
    readTable(index);
 

}






void checkFieldFrm::btnAddrecordClick(wxCommandEvent &event){
    addRecord();
}


//void checkFieldFrm::setTable(wxString table){
//    table=table;
//}


//void saveData(int index){
//    
//}

///////////////////////////////////////////////////////
////////   Get length of current data stream  ////////
/////////////////////////////////////////////////////


//int checkFieldFrm::getLength(int cpos){
//    fstream file;
//    file.open(table_name,ios::app);
//    file.seekg(cpos);
//    int as=file.tellg(),dbl=0;
//    wxString z;
//    z.Printf("%d",as);
//    wxMessageBox(a,"two");
//    wxString test;
//    char *character = new char;
//    int ind=0;
//    file.read(character,1);
//    wxMessageBox(character,"asdf");
//    if(!strcmp(character,">")){
//        wxMessageBox("asdf","asdf");
//        dbl++;
//    }
//    ind++;
//    test.Printf("%d",ind);
//    wxMessageBox(test,"Value of ind");
//    file.close();
//}

/////////////////////////////////////////////////////
////////////   Edit to current data     ////////////
///////////////////////////////////////////////////

//void getEdited(){
//
//}







void checkFieldFrm::getLastPos(){
    char *character = new char;
    int integer,length=0,exist;
    fstream file;
    file.open(table_name);
    exist=file.tellg();
    if(exist!=-1){
        while (!file.eof())          //is.good() loop while e-o-f is reached
        {
            file.read(character,1);                   // get character from file
            if((integer = ((int)*character-48))<10){    //checking for number
                length=length*10+integer;
            }
            else if(!strcmp(character,">")){
                end_pos=length;
                EPos++;
                length=0;
            }
            else if(!strcmp(character,"<")){
                for(int i=0;i<length;i++){
                    file.read(character,1);
                }
            length=0;
            }
        }
    }
    file.close();
}

void checkFieldFrm::addRecord(){
    btnEdit->SetLabel("&Save");
    Edit=2;
    for(int i=1;i<=index;i++){
        txtInput[i]->SetValue("");
        txtInput[i]->Enable();
    }

SHOW=1;


    add_record=1;
checkButtons();
}

void checkFieldFrm::setTableName(wxString a)
{
    table_name=a;
    getLastPos();
	checkField();
    checkButtons();
  	readTable(index);
}



void checkFieldFrm::checkButtons(){


//wxString a;
//a.Printf("SHOW : %d\nEdit : %d\nadd record : %d\nEPos : %d",SHOW,Edit,add_record,EPos);
//wxMessageBox(a);
    ////////////////////////////////////////////prev

    if(SHOW==1 || Edit==1 || Edit==2){
        btnPrevious->Enable(false);
    }
    else{
        btnPrevious->Enable(true);
    }
    //delete
    if(add_record || Edit==1 || Edit==2){
        btnDelete->Enable(false);
    }
    else{
        btnDelete->Enable(true);
    }
    ////////////////////////////////////////////next
    if(SHOW==EPos || Edit==1 || Edit==2){
        btnNext->Enable(false);
    }
    else{
        btnNext->Enable(true);
    }    
    //add
    if(add_record || Edit==1 || Edit==2){
        btnAddrecord->Enable(false);
    }
    else{
        btnAddrecord->Enable(true);
    }
}

/*
 * Mnudeletetable1002Click
 */
void checkFieldFrm::Mnudeletetable1002Click(wxCommandEvent& event)
{
	// insert your code here
	wxString a;
	unlink(table_name);
	unlink(table_info);
	if(wxRemoveFile(table_name) && wxRemoveFile(table_info)){
        wxMessageBox("Table deleted");
    }
    else{
        wxMessageBox("Cannot delete table");
    }
}

/*
 * Mnulist1003Click
 */
void checkFieldFrm::Mnulist1003Click(wxCommandEvent& event)
{
	// insert your code here
	//////code for listing/////
////remove this////////
	
	
	
	
}

/*
 * Mnueditableview1006Click
 */
void checkFieldFrm::Mnueditableview1006Click(wxCommandEvent& event)
{
   

/////////////////////////////////////////
////pass table name to another frame////
///////////////////////////////////////
//checkFieldFrm* field = new checkFieldFrm(this);
	// insert your code here
}

/*
 * Mnusubmenuitem21004Click
 */
void checkFieldFrm::Mnusubmenuitem21004Click(wxCommandEvent& event)
{
    
}    
    
    

/*
 * Mnuviewcompletelist1002Click
 */
void checkFieldFrm::Mnuviewcompletelist1002Click(wxCommandEvent& event)
{
	// insert your code here
	ListViewFrm *list = new ListViewFrm(this);
	//list->cwd(current_wd);
	list->Show();
    
    
    
    
    
    
    
    
    wxString table_info;
    int Xpos=0;
int countline=0;
    int count=0;
    table_info=table_name+".info";
    fstream fp2tableinfo;
    fp2tableinfo.open(table_info,ios::in);
    
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
                    wxStaticText *fields;
                   
                    fp2tableinfo.read(dum,1);
                    dum[1]='\0';
                     if(dum[0]=='\n')
                        count=0;
                    if(dum[0]=='.')
                    {
                        
                        count++;
                        if (count==2)
                        {
                           
                        fields = new wxStaticText(list,1, dummy, wxPoint(Xpos,10), wxDefaultSize, 0, wxT("WxStaticText1"));
                        Xpos+=100;
                        
                    }
                    
                   
                        
                
                        dummy.clear();
                         strcpy(dum,"\0");
                    }
                    
	           dummy=dummy+dum;
	            strcpy(dum,"\0");
    }
    
    
}
//	wxButton *Button_Next;
                
            //	Button_Next = new wxButton(list, 1, wxT("Next"), wxPoint(300, 500), wxSize(86, 29), 0, wxDefaultValidator, wxT("Button_Next"));
int store[50];
int maxlt=checklongtext(store);

fstream fp2table;
fp2table.open(table_name,ios::in);

int count1=1;
    char dummy1[1000];
    bool isenter;
  char temp[2];
  char dum1[2];
    int XPos=0;
       int YPos=0;
        int flag=1;
     
    int i=0;
  while(1)
    {
        if(fp2table.eof())
        {
               wxStaticText *data;
            if(flag==1)
            data = new wxStaticText(list,1, wxT(dummy1), wxPoint(XPos,YPos), wxDefaultSize, 0, wxT("WxStaticText1"));
            break;
        }
        else
        {
    
          // if(countline%5==0)
        //{
                
        //Button_Next->Enable(true);
            	
           
            //} 
         //   else
           // {
          
          
             for(int j=1;j<=maxlt;j++)
               {
                    if(store[j]==count1)
                    {
                        flag=0;
                     
                    }
                }   
                
                  strcpy(dum1,"\0");
                    wxStaticText *data;
                    fp2table.read(dum1,1);      
                
                 strcpy(temp,dum1);
                 strcat(dummy1,temp);
                       if(dum1[0]=='<')
                    { 
                        if(!isenter)
                        {
                      
                        dummy1[i-2]='\0';
                        if(flag==1)
                       data = new wxStaticText(list,1, wxT(dummy1), wxPoint(XPos,YPos), wxDefaultSize, 0, wxT("WxStaticText1"));
                       strcpy(dummy1,"\0");
                      
                       XPos+=100;
                       i=0;
                       count1++;
                       flag=1;
                    }
                    isenter=false;
                    strcpy(dummy1,"\0");                      
                    i=0;
                    }
                    
                    
                     i++;
                    if(dum1[0]=='>')
                    {
                    
                      
                        isenter=true;
                        dummy1[i-3]='\0';
                       if(flag==1) 
                       data = new wxStaticText(list,1, wxT(dummy1), wxPoint(XPos,YPos), wxDefaultSize, 0, wxT("WxStaticText1"));
                       strcpy(dummy1,"\0");
                    
                       XPos=0;
                       i=0;
                    YPos+=30;
                    countline++;
                  
                    count1=1;
                    flag=1;
                    
                    }   
                    
        }
}
                    
            //}
	            


}



int checkFieldFrm::checklongtext(int store[50])
{
table_info=table_name+".info";
fstream fp2tableinfo;
fp2tableinfo.open(table_info,ios::in);
int index=1;
int count=1;

 wxString dummy;
 int i=1;
  
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
            if(dum[0]=='.')
            {
                index++;
                if (index==3)
                       strcpy(dum,"\0");
            } 
            else if(dum[0]=='\n')
            {
                count++;
            index=1;
        }
            if(index==3)
            {
                dummy=dummy+dum;
    
            
            }
         
                if(dummy=="LONGTEXT")
                {
     
                store[i]=count;
              
                i++;
                  dummy.erase();
        }
              if(dummy=="CHAR"||dummy=="INT")
                    dummy.erase();

                     
}              
  

}



return(i-1);
}


/*
 * Mnudeletetable1004Click
 */
void checkFieldFrm::Mnudeletetable1004Click(wxCommandEvent& event)
{
    

    remove(table_name);
    remove(table_name+".info");
    
    fstream fp2infodb;
      fstream fp2infodb1;
    fp2infodb.open("info.db",ios::in);
      fp2infodb1.open("info1.db",ios::out);
      wxString dummy;
      while(1)
    {
        if(fp2infodb.eof())
        {
             fp2infodb.close();
              fp2infodb1.close();
              remove("info.db");
        rename("info1.db","info.db");
                  
            
            break;
            
        }
        else
        {
               
                    char dum[2];
                 strcpy(dum,"\0");
                    fp2infodb.read(dum,1);
                    dum[1]='\0';
                      dummy=dummy+dum;
                    if(dum[0]=='.')
                    {
                         
                  
                        if(dummy!=table_name+".")
                        {
                                   fp2infodb1.write(dummy,strlen(dummy));     
                                      // fp2infodb1.write(".",1);     
                                    }
                    dummy.erase();
                      
                    }
                    
                    
                }
                
                
            }
	            
  
    
	// insert your code here
}
