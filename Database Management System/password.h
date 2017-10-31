#include<fstream>
using namespace std;


void selectDbTableFrm::Password()
{
    int exist;
        wxString oldpassword;
        char password[20];
        fstream fp2password;
        fp2password.open("password.pwd",ios::in);
        exist=fp2password.tellg();
        if(exist!=-1){
            fp2password>>password;
            Dialog_Oldpassword->ShowModal();
            oldpassword=Dialog_Oldpassword->GetValue();
            Dialog_Oldpassword->SetValue("");
            fp2password>>password;
            if (password==oldpassword){
                wxMessageBox("Continue to change password.","Message");
                createpasswordfile();
            }
            else{
                wxMessageBox("The password you entered is incorrect.");
            }
        }
        else{
            createpasswordfile();
        }
}



void selectDbTableFrm::createpasswordfile()
{
    wxString password,repassword;
    fstream fp2password;
    Dialog_Password->ShowModal();
    password=Dialog_Password->GetValue();
    Dialog_Repassword->ShowModal();
    repassword=Dialog_Repassword->GetValue();
    if (password==repassword)
    {
        fp2password.open("password.pwd",ios::out);
        fp2password.write(password,strlen(password));
        wxMessageBox("New Password Saved","Message");
    }
    else{
        wxMessageBox("Password do not match.\nTry Again.");
    }
    Dialog_Repassword->SetValue("");
    Dialog_Password->SetValue("");
}
