/*
* main.c
* Server program for managing clients requests, settings etc.
*/

#include "function.h"

int main(){

    HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd,SW_MAXIMIZE);
    console_settings();
    console_resize(3);
    login=fopen("save\\logins.dat","rb");
    if(login==NULL)
        admin_settings_signup();
    else
        admin_settings_signin();

    main_menu();
    start_socket();
    start_server();

    handleAccept = (HANDLE) _beginthread(thd_accept_connections,0,0);
    handleMessages = (HANDLE) _beginthread(thd_program_messages,0,0);
    //clientHandle = (HANDLE) _beginthread( thd_receive_data,0,0);

    while(1){  // The interface part
      switch(getch()){
        case '1':
                if(flag_menu==0)
                   requests();
                else if(flag_menu==2)
                    services();
                else if(flag_menu==21)
                    add_services();
                else if(flag_menu==22)
                    setcost();
                else if(flag_menu==24)
                    change_password();
                break;
            case '2':
                if(flag_menu==0)
                    settings();
                else if(flag_menu==2)
                    cost();
                else if(flag_menu==22)
                    viewcost();
                else if(flag_menu==21)
                    view_services();
                break;
            case '3':
                if(flag_menu==0){
                    saveMessagesToFile();
                    exit(0);
                }
                else if(flag_menu==2)
                    member_settings_signup();
                else if(flag_menu==21)
                    edit_services();
                break;
            case '4':
                if(flag_menu==21)
                    search_services();
                else if(flag_menu==2)
                    admin_settings();
                break;
            case '5':
                if(flag_menu==21)
                    delete_services();
                         break;
            case 'r':
                if(flag_menu == 0)
                    flag_reset = true;
                    main_menu();
                    break;

            case 27:
                if(flag_menu==2 || flag_menu==1 )
                    main_menu();
                else if(flag_menu==21)
                     settings();
                else if( flag_menu==22)
                     settings();
                else if(flag_menu==23)
                     settings();
                else if(flag_menu==24)
                     settings();
                else if(flag_menu==211)
                     services();
                else if(flag_menu==212)
                     services();
                else if(flag_menu==213)
                     services();
                else if(flag_menu==214)
                     services();
                else if(flag_menu==215)
                     services();
                else if(flag_menu==221 || flag_menu==222)
                     cost();
                break;
            default:
                break;
            }
        }
return 0;
}

