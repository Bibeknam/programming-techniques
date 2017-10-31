int out=0,num,num1,dbno;
bool enablemenu;
//StaticText_db1->Hide();

/////////////////////////////////////////button select clicked/////////////////////

void selectDbTableFrm::btnSelectClick(wxCommandEvent& event)
{
//
//    wxString select=txtSelect->GetValue();
//    for(int i=0;i<2;i++){
//            db[i]->Destroy();
//        }
//    //displayTable(select);
//    /*int pos,integer,length=0,exist=0;
//    char *file_input,*character=new char;
//
//    fstream file;
//    file.open ("");        // open file
//    
//    while (!file.eof())                               //is.good() loop while e-o-f is reached
//    {
//        file.read(character,1);                       // get character from file
//        if((integer = ((int)*character-48))<10){    //checking for number
//            length=length*10+integer;	
//        }
//        else if(length){
//            pos = file.tellg();           //get current position
//            --pos;
//            file.seekg(pos);              //go back one setp back in file stream
//            file_input= new char[length];
//            file.read(file_input,length);
//            wxMessageBox(file_input,select);
//            if(file_input==select){
//                
//                
//               //db[1]->Hide(); 
//            //db[0]->Hide();
//            //Refresh();
//                
//                
//                
//                
//                
//                displayTable(file_input);
//                exist=1;
//                break;
//            }
//        length=0;
//        }
//    }
//if(!exist)
//    wxMessageBox("Invalid Entry","Info",wxICON_ERROR);
//  file.close(); */          // close file
//  
}



///////////////////////////////////////text updated/////////////////////

void selectDbTableFrm::txtSelectUpdated(wxCommandEvent& event){
chdir(current_wd);
enablemenu=false;
for(int i=0;i<num1;i++)
{
    table[i]->Hide();
}
    wxString prev,select,test,file_input;
    select.erase();
    select=txtSelect->GetValue();
    int Ypos=60,pos,integer,length=0,exist=1,txtLength=txtSelect->GetLastPosition();
    static int times,no_of_options,tim;
    int first=0,erase=1;
    char *character=new char;

    if(nstart)
        for(int i=0;i<times;i++){
            db[i]->Destroy();
        }
    nstart=1;
    times=0;
    first=1;
    erase=0;


    tim=times;

    ifstream file;
    file.open ("db.txt");        // open file
int i=file.tellg();
    if(i==-1){
        wxMessageBox("No database created");
    }
    else{
        while (!file.eof())                               //is.good() loop while e-o-f is reached
        {
            file.read(character,1);                       // get character from file
    
            if((integer = ((int)*character-48))<10){    //checking for number
                length=length*10+integer;
            
            
            }
            else if(length){
                
                no_of_options++;
                pos = file.tellg();           //get current position
                --pos;
                file.seekg(pos);              //go back one setp back in file stream
                file_input.erase();
                for(int i=0;i<length;i++){
                    file.read(character,1);
                    file_input+=character;
                }
                for(int i=0;i<txtLength;i++){
                    if(!(select[i]==file_input[i])){
                        exist=0;
                        break;
                    }
                }
                if(exist){
                    prev=file_input;
                    db[times] = new wxHyperlinkCtrl(this, 1,file_input, file_input, wxPoint(15, Ypos), wxDefaultSize, wxNO_BORDER | wxHL_CONTEXTMENU);
  
                    //db[times]->SetLabel(wxT("jfkjdslkf"));
                    Ypos+=20;
                    times++;
                    
                }
                num=times;
                exist=1;
                length=0;
            }
            
        }
    }
    file.close();

}



////////////////////////////////////////////display table lists/////////////////////////

void selectDbTableFrm::displayTable(wxString db){
    
    chdir(db);
    out = 1;                    // define, CWD is changed
    fstream pwd;
    wxString pass;
    char *password = new char;;
    pwd.open("password.pwd");
    int pwdpos=pwd.tellg();
    if(pwdpos!=-1){
        pwd.seekg(0,ios::end);
        pwdpos=pwd.tellg();
        pwd.seekg(0,ios::beg);
        password = new char[pwdpos];
        pwd.read(password,pwdpos);
        pass = wxGetPasswordFromUser("Enter password");
        if(pass==password){
            showTables();
        }
        else
            wxMessageBox("Incorrect Password");
        
    }
    else{
        showTables();
    }




}


////////////////////////////////////get tables lists///////////////////////////////

void selectDbTableFrm::getTables(wxHyperlinkEvent& event)
{
    wxString db1=event.GetURL();
    enablemenu=true;	
    //	StaticText_db1->Hide();
    dname=db1;
    
    for(int i=0;i<num;i++)
    {
    if(db1!=db[i]->GetURL())
        db[i]->Hide();
    else
    dbno=i;
}
    displayTable(db1);
    
}

/////////////////////////////////get table content//////////////////////////////

void selectDbTableFrm::getContens(wxHyperlinkEvent& event)
{
    out=1;                  // define, PWD is changed
    table_name = event.GetURL();

/////////////////////////////////////////
////pass table name to another frame////
///////////////////////////////////////
    
    checkFieldFrm* field = new checkFieldFrm(this);
    field->setTableName(table_name);
    field->Show();
}

  ///////////////////////////////////
 /////////pass table name///////////
///////////////////////////////////

wxString selectDbTableFrm::getTableName(){
        out=1;                  // define, PWD is changed
    return table_name;
}



void selectDbTableFrm::showTables(){
        static int times;
        int Ypos=60;
        for(int i=0;i<times;i++)
        {
            table[i]->Destroy();
        }
        times=0;
    
        wxString file_input;
        fstream file;    
        file.open("info.db",ios::in); 
        int check=file.tellg();
        if(check!=-1){
            while(!file.eof()){
                char *character = new char;
                file.read(character,1);
                if(!strcmp(character,".")){
                    table[times] = new wxHyperlinkCtrl(this, 2 ,file_input,file_input , wxPoint(300, Ypos), wxDefaultSize, wxNO_BORDER | wxHL_CONTEXTMENU);
                    Ypos+=20;
                    times++;
                    file_input.Empty();
                }
                else
                    file_input+=character;
            }
            num1=times;
            file.close();
        }
        else{
            int choice= wxMessageBox("No tables created\nDo you want to create new?","Message",wxYES_NO);
            if(choice==wxYES){
                  //////////////////////////////////////////////////////////////////
                 ////////////////goto create frame/////////////////////////////////
                //////////////////////////////////////////////////////////////////
            }
        }
}
