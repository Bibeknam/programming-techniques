/*
* interface.h
* Server side Interface related functions and threads
* @author: <base-2>
* Date:- 9-11-2010
*/

// The first menu seen after server logins in the system

void main_menu(){
    FILE *sInfo;
    sInfo = fopen("save\\serverInfo.txt","r");
    flag_menu = 0;
    char sDate[13];
    int cn = 7,i,count = 9;
    system("cls");
    for(i=0;i<56;i++){
        gotoPrint(90,i,"|");
    }

    //reset nu of requests
    if(flag_reset==true){
         for(i=0;i<no_of_clients;i++){
                    c[i].r.num_request = 0;
         }
     }
    flag_reset = false;
    /*if(flag_reset == true){
      for(i=0;i<no_of_clients;i++){
            if(c[i].connected == false)
                no_of_clients--;
         }
    }
    */
    //flag_reset = false;
    getDate(sDate);
    fscanf(sInfo,"%s",cyberName);
    gotoPrint(35,1,cyberName);
    gotoxy(60,1); printf("Today:- %s",sDate);
    gotoPrint(23,3,"------------------------------------");
    gotoPrint(25,4,"1.Requests  2. Settings  3. Exit ");
    gotoPrint(23,5,"------------------------------------");
    gotoPrint(5,cn,"Clients");
    gotoPrint(20,cn,"Requests Pending");
    gotoPrint(40,cn,"Login Time");
    gotoPrint(55,cn,"Logout Time");
    gotoPrint(75,cn,"Cost");
    if(no_of_clients>0){
        for(i=0;i<no_of_clients;i++){
                gotoxy(7,count+i*2);
                printf("%d",c[i].id);
                gotoxy(30,count+i*2);
                printf("%d",c[i].r.num_request);
                gotoxy(45,count+i*2);
                printf("%d:%d",c[i].logIn.hr,c[i].logIn.min);
                if(c[i].active == false){
                    gotoxy(60,count+i*2);
                    printf("%d:%d",c[i].logOut.hr,c[i].logOut.min);
                    gotoxy(75,count+i*2);
                    printf("Rs. %d",c[i].cost);
                }
        //}
        }
    }
    flag_newMsg = true;
    //gotoPrint(10,10,"No Clients Connected");
}


void console_settings() {
   //EnableMenuItem(GetSystemMenu(GetConsoleWindow(), FALSE), SC_CLOSE , MF_GRAYED);
   // RemoveMenu(GetSystemMenu(GetConsoleWindow(), FALSE), SC_CLOSE , MF_GRAYED);
    //RemoveMenu(GetSystemMenu(GetConsoleWindow(), FALSE), SC_MINIMIZE , MF_BYCOMMAND);
    //RemoveMenu(GetSystemMenu(GetConsoleWindow(), FALSE), SC_SIZE , MF_BYPOSITION);
    //RemoveMenu(GetSystemMenu(GetConsoleWindow(), FALSE), SC_MOVE , MF_BYPOSITION);
    EnableMenuItem(GetSystemMenu(GetConsoleWindow(), FALSE), SC_MAXIMIZE , MF_GRAYED);
    RemoveMenu(GetSystemMenu(GetConsoleWindow(), FALSE), SC_MAXIMIZE , MF_GRAYED); //disab;e
    DrawMenuBar(GetConsoleWindow());
}

HWND WINAPI GetConsoleWindowNT()
{
    // declare function pointer type

    typedef HWND WINAPI (*GetConsoleWindowT)(void);

    // declare one such function pointer

    GetConsoleWindowT GetConsoleWindow;

    // get a handle on kernel32.dll

    HMODULE hK32Lib = GetModuleHandle(TEXT("KERNEL32.DLL"));

    // assign procedure address to function pointer

    GetConsoleWindow = (GetConsoleWindowT)GetProcAddress(hK32Lib,TEXT("GetConsoleWindow"));

    // check if the function pointer is valid

    // since the function is undocumented

    if ( GetConsoleWindow == NULL ) {
         return NULL;
    }

    // call the undocumented function

    return GetConsoleWindow();

}
void reset_console() {
        CONSOLE_SCREEN_BUFFER_INFO SBInfo;
        HWND hWnd = GetConsoleWindowNT();
    COORD NewSBSize;

    int Status;
/* Resetting the console size and buffer */
    NewSBSize.X = 13;
    NewSBSize.Y = 2;


    Status = MoveWindow(hWnd,0,0,50,50,TRUE);

    if (Status == 0)
    {
        printf("Failed:: reset console size");
    }

   Status = SetConsoleScreenBufferSize(hOut, NewSBSize);
    if (Status == 0)
    {
        printf("Failed:: reset console buffer");
    }
}


void console_resize(int console_id) {
    reset_console();
    DWORD max_resX = GetSystemMetrics(SM_CXSCREEN);
    DWORD max_resY = GetSystemMetrics(SM_CYSCREEN);
    CONSOLE_SCREEN_BUFFER_INFO SBInfo;
    HWND hWnd = GetConsoleWindowNT();
    COORD NewSBSize;
    int Status,L,T,R,B;


    if (console_id == 1) {
        NewSBSize.X = 35;
        NewSBSize.Y = 7;
        T = max_resY-150;
        B = 150;
        L = max_resX-300;
        R = 300;

    } else
    if (console_id == 2) {
        NewSBSize.X = 35;
        NewSBSize.Y = 45;
        T = max_resY-600;
        B = 600;
        L = max_resX-300;
        R = 300;
    } else if (console_id == 3) {
        NewSBSize.X = max_resX/8;
        NewSBSize.Y = max_resY/12;
        T = 0;
        L = 0;
        R = max_resX;
        B = max_resY;
    }




    Status = SetConsoleScreenBufferSize(hOut, NewSBSize);
    if (Status == 0)
    {
        printf("Failed:: resize console size");
    }

    Status = MoveWindow(hWnd,L,T,R,B,TRUE);

    if (Status == 0)
    {
        printf("Failed:: resize console size");
    }
    //printf("%d,%d,%d,%d--%d,%d",L,T,R,B,NewSBSize.X,NewSBSize.Y); getch();
}
