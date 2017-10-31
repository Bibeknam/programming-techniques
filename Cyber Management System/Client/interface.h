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
//Interface Layout
void window(void)
{
    int i;
    int down=18,left=51,right=131;
    for(i=left;i<=81;i++)
    {
        gotoxy(i,down);printf("\xB2");
    }
    for(i=101;i<=right;i++)
    {
        gotoxy(i,down);printf("\xB2");
    }
    for(i=down;i<=left-3;i++)
    {
        gotoxy(left,i);printf("\xB2");
    }
    for(i=left;i<=right;i++)
    {
        gotoxy(i,left-3);printf("\xB2");
    }
    for(i=down;i<=left-3;i++)
    {
        gotoxy(right,i);printf("\xB2");
    }
    gotoxy(right-8,left-4);printf("C. YBER");
    //gotoxy(left+2,left-4);printf("Back : ESC");
 }

void login_screen() {
    int mid=85,down=18;
    console_resize(3);

    system("cls");
    window();
    gotoxy(mid,down);printf("Log In Screen\n");
    gotoxy(mid,down+2);printf("C.yber Client\n");
    gotoxy(mid,down+4);printf("Cyber XYZ\n");
    gotoxy(mid-5,down+7);printf("1. Sign in as Member\n");
    gotoxy(mid-5,down+10);printf("2. Sign in as Guest\n");

    gotoxy(58,35);printf("Select an option:: ::");
    char sel;
    while(1) {
        sel = getch();
        if (sel == '1' || sel == '2') {
            break;
        }

    }
    switch (sel) {
        case '1':
            while(1) {
                system("cls");
                window();
                gotoxy(mid,down); printf("Member Sign In");
                gotoxy(mid,down+2);printf("Username::\t");gets(username);
                gotoxy(mid,down+4);printf("Password::\t");get_password(password);
                //action to check username and password
                is_member = 1;

                if(confirm_member()) {
                    break;
                } else {
                    MessageBox(0,"Invalid Username Or Password:: Please Try Again!","Error",0);
                    strcpy(username,"");
                    strcpy(password,"");
                    log_stat = 0;
                }
            }
            break;
        case '2':
            char Message[STRLEN], repMessage[STRLEN];
            is_member = 0;
            createMessage(Message);
            c_send_data(Message);
            c_recv_data(repMessage);
            for(i=2;repMessage[i]!=':';i++) {
                CyberName[i-2] = repMessage[i];
            }
            CyberName[i-1] = '/0';
            i++; char x[4];
            for(j=i;repMessage[j]!=':';j++) {
                x[j-i] = repMessage[j];
            }
            x[j-i-1] = '/0';
            fixed_rate = atoi(x);
            break;
    }
    tot_service = get_service_info();
    log_stat = 1;
    //continue to tray
}


void main_menu(){  //main menu
    console_resize(1);
    //move_window();
    system("cls");
    printf("** Welcome To %s **\n\n\n\n\n",CyberName);
    printf("Press F2 to see menu.");
    gotoxy(0,2);printf("Timer:\t\t    Price:");
}


void gotoxy (int x, int y)
{
        coord.X = x; coord.Y = y; // X and Y coordinates
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
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


void show_menu() {
    flag_menu=0;
    console_resize(2);
    system("cls");
    gotoxy(10,4); printf("%s Menu",CyberName);
    gotoxy(10,8);printf("1. Order Service");
    gotoxy(10,10);printf("2. Credits");
    gotoxy(10,12);printf("3. Log Out");
     gotoxy(0,2);printf("Timer:\t\t    Price: ");
    //gotoxy(5,18);printf("Press Esc to go back to default console");
    gotoxy(0,16); printf("Select an Item::");
    gotoxy(0,20);printf("ESC -> Back\tT -> Tray Console\nH -> Help");
}

void service_menu() {
    flag_menu=1;
    system("cls");
    printf("C.yber-Client");
    gotoxy(10,4); printf("%s Service Menu",CyberName);
    gotoxy(5,8);printf("Item Name");
    gotoxy(20,8);printf("Rate(Rs.)");


    for ( i = 0; i<=tot_service-1; i++) {
        gotoxy(5,10+i); printf("%d. %s",i+1,items[i].name);
        gotoxy(25,10+i); printf("%d",items[i].rate);
    }

    gotoxy(0,2);printf("Timer:\t\t    Price: ");
    //gotoxy(5,18);printf("Press Esc to go back to default console");
    gotoxy(0,tot_service+14); printf("Select an Item::");
    gotoxy(0,tot_service+18);printf("T -> Tray Console\tESC -> Back\nH -> Help");
    int breakLoopFlag = 0;
    while(1) {
        char sel = tolower(getch());
        if (sel == 't') {
            to_tray = 1;
            breakLoopFlag = 1;
        } else
        if(sel == 27) {
            to_tray = 4;
            breakLoopFlag = 1;
        } else
        if(sel == 'h') {
            to_tray = 3;
            breakLoopFlag = 1;
        } else {
            int serv_id = atoi(&sel);
            for(i=1;i<=tot_service;i++) {
                if(serv_id == i) {
                    char Message[STRLEN],repMessage[1];
                    service_id = serv_id;
                    cost_changed = items[service_id-1].rate;
                    createMessage(Message);
                    c_send_data(Message);
                    c_recv_data(repMessage);
                    service_id = 0;
                    if(repMessage[0]=='1') {
                        MessageBox(0,"Your Order Will Be Delivered Soon","Service Message",0);
                        to_tray = 4; breakLoopFlag = 1; break;
                    } else if (repMessage[0] = '0'){
                        MessageBox(0,"Sorry! We are out of that...","Service Message",0);
                        to_tray = 4; breakLoopFlag = 1; break;
                    }
                }
            }
        }
        if(breakLoopFlag) {break;} //condition to end the infinite loop
    }

}

void settings_menu() {
    flag_menu=2;

//Requesting Server for informations on services

    char buffer[STRLEN],a[3],b[2];
    intToString(computer_id,a);
    intToString(is_member,b);
    strcat(buffer,a);strcat(buffer,":");
    strcat(buffer,"0");strcat(buffer,":"); //service_id
    strcat(buffer,"3");strcat(buffer,":"); //log_stat
    strcat(buffer,b);strcat(buffer,":");
    c_send_data(buffer);

//Requesting Server for informations on services

//accepting service informations and printing the menu
    char recMessage[STRLEN];
    c_recv_data(recMessage);
    int msgExtracted[4];
//    readMessage(msgExtracted,recMessage);

    system("cls");
    printf("C.yber-Client");
    gotoxy(10,4); printf("Cyber XYZ Settings");
    gotoxy(10,8);printf("1. Change Computer ID");
    gotoxy(10,10);printf("2. Change Password");
    gotoxy(10,12);printf("3. Change Server IP");
    gotoxy(0,2);printf("Timer:\t\t    Price: ");
    //gotoxy(5,18);printf("Press Esc to go back to default console");
    gotoxy(0,16); printf("Select an Item::");
    gotoxy(0,20);printf("T -> Tray Console\tESC -> Back\nH -> Help");
//accepting service informations and printing the menu
}

void credits() {
    flag_menu=3;
    system("cls");
    printf("C.yber-Client");
    gotoxy(10,4); printf("CODDED BY");
    gotoxy(8,5);printf("-----------------");
    gotoxy(10,6);printf("<BASE 2 />");
    gotoxy(6,8);printf("1. Aayush Shrestha");
    gotoxy(6,9);printf("2. Ashok Basnet");
    gotoxy(6,10);printf("3. Bibek Subedi");
    gotoxy(6,11);printf("4. Dinesh Subedi");
    gotoxy(2,12);printf("066 BCT , IOE pulchowk campus");
    gotoxy(2, 14);printf("No copyright (C) protected: ");
    gotoxy(2,16);printf("We love open source");
    gotoxy(0,2);printf("Timer:\t\t    Price: ");
    gotoxy(0,20);printf("T -> Tray Console\tESC -> Back\nH -> Help");
    to_tray = 0;
}


void log_out() {
    console_resize(1);
    log_stat = 2; // 2 means logging out status
    service_id = tot_cost;
    char Message[STRLEN];
    createMessage(Message);
    c_send_data(Message);
    system("cls");
    printf("Logging out");
    for(i=0;i<=5;i++) {
        delay(300);
        printf(".");

    }
    reset_variables();
}

void help_window() {
    flag_menu=9;
    system("cls");
    gotoxy(2,4);printf("HELP File");
    gotoxy(1,5);printf("-------------------------");
    gotoxy(2,7);printf("F2 -> To maximize the size of");
    gotoxy(2,8);printf("      Console");
    gotoxy(2,9);printf("T -> To minimize the size of ");
    gotoxy(2,10);printf("    Console");
    gotoxy(2,11);printf("H -> For Help");
    gotoxy(2,12);printf("Esc -> For back");
    gotoxy(0,2);printf("Timer:\t\t    Price: ");
    gotoxy(0,20);printf("T -> Tray Console\tESC -> Back\nH -> Help");
}

void console_settings() {
    EnableMenuItem(GetSystemMenu(GetConsoleWindow(), FALSE), SC_CLOSE , MF_GRAYED);
    RemoveMenu(GetSystemMenu(GetConsoleWindow(), FALSE), SC_CLOSE , MF_GRAYED);
    RemoveMenu(GetSystemMenu(GetConsoleWindow(), FALSE), SC_MINIMIZE , MF_BYCOMMAND);
    RemoveMenu(GetSystemMenu(GetConsoleWindow(), FALSE), SC_SIZE , MF_BYPOSITION);
    RemoveMenu(GetSystemMenu(GetConsoleWindow(), FALSE), SC_MOVE , MF_BYPOSITION);
    RemoveMenu(GetSystemMenu(GetConsoleWindow(), FALSE), SC_MAXIMIZE , MF_GRAYED);
    DrawMenuBar(GetConsoleWindow());
}
