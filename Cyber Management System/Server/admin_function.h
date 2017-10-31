/*
	File:- admin_function.h
	Desc:- contains all the functions related to administrator back side
*/

#include "service.h"

char* getServiceName(int s_id){
    fp=fopen("save\\service.dat","rb");
    while(fread(&service1,sizeof(service1),1,fp)==1){
        if(service1.item_id == s_id)
            return service1.item_name;
    }
    fclose(fp);
}
void requests(){
    int i,j;
    bool flag_showLine;
    flag_menu = 1;
    system("cls");
    int coun = 8,dis = 0;
    if(no_of_clients>0){
        flag_reset = true;
        gotoxy(80,2);
        printf("Requests:-"); gotoxy(50,4);
        printf("-----------------------------------------------------------------------");
        gotoxy(55,5); printf("Client No          Items             Time");  gotoxy(50,6);
        printf("-----------------------------------------------------------------------");

        for(i=0;i<no_of_clients;i++){
            if(c[i].connected){
               flag_showLine = false;
                    gotoxy(60,coun+dis*2);
                    printf("%d",c[i].id);
                    for(j=0;j<c[i].r.num_request;j++){
                        flag_showLine = true;
                        gotoxy(75,coun+j*2);
                        printf("%s", getServiceName(c[i].r.service_id[j]));
                        gotoxy(93,coun+j*2);
                        printf("%d:%d",c[i].r.reqTime[j].hr,c[i].r.reqTime[j].min);
                        dis++;
                    }
                    if(flag_showLine){
                        gotoxy(50,coun+dis*2);
                        printf("-----------------------------------------------------------------------");
                    }
                }
            }
           // }
    }else{
            gotoxy(60,30); printf("\a--No Clients Connected--\a");
    }
}

void window(void)
{
    int i;
    for(i=40;i<=70;i++)
    {
        gotoxy(i,10);printf("\xB2");
    }
    for(i=90;i<=120;i++)
    {
        gotoxy(i,10);printf("\xB2");
    }
    for(i=10;i<=40;i++)
    {
        gotoxy(40,i);printf("\xB2");
    }
    for(i=40;i<=120;i++)
    {
        gotoxy(i,40);printf("\xB2");
    }
    for(i=10;i<=40;i++)
    {
        gotoxy(120,i);printf("\xB2");
    }
    gotoxy(112,39);printf("C. YBER");
    gotoxy(42,39);printf("Back : ESC");
 }

char* password()
{
    char *Password,temp_passP[25],PasswordP[25];
    int i=0;
     while(1)
    {
            temp_passP[i]=getch();
            if(temp_passP[i]==13){break;}
            else if(temp_passP[i]==8)
            {

               if(i!=0) {
                printf("\b \b");
                i--;
                }else {printf("\a");}
            }
            else
            {
                printf("*");
                PasswordP[i] = temp_passP[i];
                i++;
            }
             PasswordP[i]='\0';
     }
     Password=PasswordP;
     return Password;
}

void member_settings_signup(void)
{
    int leftpos=73;
    char  passMe[25];
    system("cls");
    window();
    gotoxy(75,10);printf("ADD MEMBERS");
    flag_menu=23;
    char confirmMe[25];
    char ch, temp_user[25];
    int i=0,flag=0,j=1;
    fflush(stdin);
  //  gotoxy(13,22);printf("Warning! Password Must Contain six(6) Alphanumeric Digits." );
    gotoxy(leftpos,15);printf("Username:");
    gotoxy(leftpos,18);printf("Password:");
    gotoxy(leftpos,21);printf("Confirm password:");
    gotoxy(leftpos+13,15);gets(temp_user);
    if(check_username(temp_user)==0)
    {

        gotoxy(leftpos,35);printf("Username already exists. Try another one");
    }else{
    strcpy(login1.username,temp_user);
    gotoxy(leftpos+13,18);
    strcpy(passMe,password());
    gotoxy(93,21);
    strcpy(confirmMe,password());
    login1.flag_admin=0;
    if(strcmp(passMe,confirmMe)==0)
    {
        strcpy(login1.password,passMe);
        gotoxy(leftpos,24);printf("Your account has been created");
        gotoxy(leftpos,26);printf("Your Username is %s",login1.username);
        gotoxy(leftpos,28);printf("Thank You for joining with us");
        //MessageBox(0,"Welcome! Your account has been created","Information ",0);
        flag=2;
    }
    else
    {
        gotoxy(leftpos,21);printf("Password do not match");
        gotoxy(leftpos,23);printf("Press any key to continue");
        flag=1;
    }
    if(flag==2)
    {
        login=fopen("save\\logins.dat","ab+");
        if(login==NULL)
        {
            printf("Cannot open file");
            exit(1);
        }

        fseek(login,-sizeof(login1),SEEK_CUR);
        fwrite(&login1,sizeof(login1),1,login);
        fclose(login);
    }

    }

}


void member_settings_signin(void)
{
    int leftpos=73;
    system("cls");
    char temp_username[25],pass[25];
    int flag = 0;
    int i=0;
    gotoxy(leftpos,3);printf("Username:");
    gotoxy(leftpos,5);printf("Password:");
    gotoxy(leftpos+10,3); gets(temp_username);
    gotoxy(leftpos+10,5);
    strcpy(pass,password());
    login=fopen("save\\logins.dat","rb");
    while(fread(&login1,sizeof(login1),1,login)==1)
    {
        if(strcmp(login1.username,temp_username)==0 && strcmp(login1.password,pass)&&login1.flag_admin!=1)
        {
            flag = 1;
        }

    }
    fclose(login);
    gotoxy(25,7);
  //  system("cls");
    printf("\n");
    if(flag == 1){
        printf("LOGIN Successful\n");
      //  MessageBox(0,"Login Successful","Alert message",0);
    }
    else{

        //printf("Invalid username or password\n");
        MessageBox(0,"Invalid Username or Password","Alert message",0);
    }
}
int check_username(char username[25])
{
    FILE *loginChk;
    loginChk=fopen("save\\logins.dat","rb");
    while(fread(&login1,sizeof(login1),1,loginChk)==1)
    if(strcmp(login1.username,username)==0 && login1.flag_admin!=1)
    {
        fclose(loginChk);
        return 0;
    }
    return 1;
}


void settings()
{
    int leftpos=73;
    system("cls");
    window();
    flag_menu=2;
    gotoxy(76,10);printf("SETTINGS");
    gotoxy(leftpos,15);printf("1. Services");
    gotoxy(leftpos,18);printf("2. Cost");
    gotoxy(leftpos,21);printf("3. Add Members");
    gotoxy(leftpos,24);printf("4. Admin Settings");
    gotoxy(leftpos,27);printf("Enter Your Choice: ");
}

void cost(void)
{
    int leftpos=73;
    system("cls");
    window();
    flag_menu=22;
    gotoxy(74,10);printf("COST MANAGING");
    gotoxy(leftpos,15);printf("1. Set Cost");
    gotoxy(leftpos,18);printf("2. View Cost");
    gotoxy(leftpos,21);printf("Enter Your Choice");

}

void setcost (void)
{
    system("cls");
    window();
    flag_menu=221;
     fcost=fopen("save\\rate.dat","wb");
    gotoxy(74,10);printf("COST SETTINGS");
    gotoxy(72,13);printf("The cost upto 1 hrs is : ");
    gotoxy(97,13);scanf("%d",&cost1.rate);
    //cost1.time=1;
    fseek(fcost,0,SEEK_CUR);
    fwrite(&cost1,sizeof(cost1),1,fcost);
    fclose(fcost);
    gotoxy(72,15);printf("cost is set");
}

void viewcost(void)
{
    system("cls");
    int i;
    window();
    flag_menu=222;
    gotoxy(76,10);printf("VIEW COST");
    gotoxy(62,15);printf("Time ");gotoxy(82,15);printf("Cost");
    fcost=fopen("save\\rate.dat","rb");
    while(fread(&cost1,sizeof(cost1),1,fcost)==1)
    {
                gotoxy(62,14+i);printf("Per Hour : %d",cost1.rate);
                //gotoxy(34,4+i);printf("Rs.%.2f",cost1.rate[i]);
    }
    fclose(fcost);
}

void admin_settings_signup()
{
    FILE *SInfo;
    int leftpos=73;
    system("cls");
    window();
    int flag=0;
    char passMe[25],confirmMe[25];
    gotoxy(73,10);printf("C.yber Setup");
    gotoxy(leftpos,15);printf("Username:");
    gotoxy(leftpos,17);printf("Password:");
    gotoxy(leftpos,19);printf("Confirm Password:");
    gotoxy(leftpos+10,15);fflush(stdin);gets(login1.username);
    gotoxy(leftpos+10,17);strcpy(passMe,password());
    gotoxy(leftpos+18,19);strcpy(confirmMe,password());
    if(strcmp(passMe,confirmMe)==0)
    {
        char sName[50],sAddress[50],sOwner[20];
        strcpy(login1.password,passMe);
        gotoxy(leftpos,22);printf("Congratulations !! Your account is created");
        gotoxy(leftpos-10,25);printf("Cyber Name:- ");
        gotoxy(leftpos-10,27);printf("Address:- ");
        gotoxy(leftpos-10,29);printf("Owner:");
        gotoxy(leftpos+5,25);fflush(stdin);gets(sName);
        gotoxy(leftpos+5,27);fflush(stdin);gets(sAddress);
        gotoxy(leftpos+5,29);fflush(stdin);gets(sOwner);
        SInfo = fopen("save\\serverInfo.txt","w+");
        fprintf(SInfo,"%s\n%s\n%s",sName,sAddress,sOwner);
        fclose(SInfo);
        gotoxy(leftpos+5,32); printf("Press any key to continue...");
        flag=3;

    }
    else
    {
        gotoxy(leftpos,20);printf("Password Do not match");
        gotoxy(leftpos,21);printf("Try again!!");
        getch();
        admin_settings_signup();
    }
    if(flag==3)
    {
        login=fopen("save\\logins.dat","wb+");
        if(login==NULL)
        {
            printf("cannot open file");
            exit(1);
        }
        login1.flag_admin=1;
        fseek(login,-sizeof(login1),SEEK_CUR);
        fwrite(&login1,sizeof(login1),1,login);
        fclose(login);
        getch();
    }
}

void admin_settings_signin()
{
    int leftpos=73;
    system("cls");
    window();
    char temp_username[25],temp_password[25];
    int flag=0;
    gotoxy(74,10);printf("Login Process");
    gotoxy(leftpos,13);printf("Username: ");
    gotoxy(leftpos,15);printf("Password:");
    gotoxy(leftpos+10,13);gets(temp_username);
    gotoxy(leftpos+10,15);strcpy(temp_password,password());
    login=fopen("save\\logins.dat","rb");
    if(login==NULL)
    {
        printf("Unable to open file");
        exit(1);
    }
    while(fread(&login1,sizeof(login1),1,login)==1)
    {
        if(strcmp(login1.username,temp_username)==0 && strcmp(login1.password,temp_password)==0 && login1.flag_admin==1)
        {
                flag=4;
        }
    }
    fclose(login);
    if(flag==4)
    {
        gotoxy(leftpos,17);printf("Login Sucessful");
        getch();
    }
    else
    {
        gotoxy(leftpos,17);printf("Invalid username or password");
        getch();
        admin_settings_signin();
    }
}
void admin_settings()
{
    int leftpos=73;
    system("cls");
    window();
    flag_menu=24;
    gotoxy(leftpos+1,10);printf("ADMIN SETTINGS");
    gotoxy(leftpos,13);printf("1. Change Password");
    gotoxy(leftpos,17);printf(" Enter Your Choice:- ");
}

void change_password()
{
    int leftpose1=38;
    system("cls");
    char old_password[25],new_pass[25],confirm_pass[25];
    int flag=0;
    window();
    flag_menu=24;
    gotoxy(leftpose1+32,10);printf("CHANGING PASSWORD");
    gotoxy(leftpose1+20,13);printf("Enter old password: ");
    gotoxy(leftpose1+20,15);printf("Enter new password:");
    gotoxy(leftpose1+20,17);printf("Re-enter new password");
    gotoxy(leftpose1+40,13);strcpy(old_password,password());
    gotoxy(leftpose1+41,15);strcpy(new_pass,password());
    gotoxy(leftpose1+43,17);strcpy(confirm_pass,password());
    if(strcmp(new_pass,confirm_pass)==0)
    {
        flag=5;
    }
    login=fopen("save\\logins.dat","rb+");
    if(login==NULL)
    {
        printf("Unable to open file");
        exit(1);
    }
    while(fread(&login1,sizeof(login1),1,login)==1)
    {
        if(strcmp(old_password,login1.password)==0&& login1.flag_admin==1)
        {
            if(flag==5)
            {
                strcpy(login1.password,new_pass);
                fseek(login,-sizeof(login1),SEEK_CUR);
                fwrite(&login1,sizeof(login1),1,login);
                fclose(login);
                flag=6;
            }
        }

    }
    if(flag==6)
    {
        gotoxy(leftpose1+25,19);printf("The password is successfully changed");
        gotoxy(leftpose1+25,20);printf("Press any key to continue");
    }
    else
    {
            gotoxy(leftpose1+25,19);printf("Password changing process failed");
            gotoxy(leftpose1+25,20);printf("Try again!!");
    }
}

