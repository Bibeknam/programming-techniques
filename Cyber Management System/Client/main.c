#include "function.h"

int main(){
   console_settings();

    ip=fopen("ip_add.dat","rb");
    if(ip==NULL){
            ip=fopen("ip_add.dat","wb");
        gotoxy(10,5);printf("Enter IP address : ");
        gotoxy(10,7);printf("Enter port number: ");
        gotoxy(10,9);printf("Enter client number: ");
        gotoxy(29,5);fflush(stdin);gets(ip1.ip_address);
        gotoxy(30,7);scanf("%d",&ip1.port_no);
        gotoxy(32,9);scanf("%d",&ip1.client_no);
        fseek(ip,0,SEEK_END);
        fwrite(&ip1,sizeof(ip1),1,ip);
    }
    fclose(ip);
    assign_ip_address();

     HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd,SW_MAXIMIZE);
    if(!SOCKET_START){
        start_socket();
        connect_server();
        SOCKET_START=true;
    }
    start_log:
    log_stat = 0;
    login_screen(); //displays log_in screen, checks

        time_thread = (HANDLE) _beginthread( show_time,0,0);
    start_menu:
        main_menu();
        while(1){
            if(get_code()==60) {
                show_menu();
                break;
            }
        }
        char sel;
        while(1){  //send data until the clients shuts down or disconnects(end)
    //        selected=get_code();
    //        printf("pressed");
               switch (sel = tolower(getch())) {
                    case '1':
                        if(flag_menu==0) {
                            service_menu();
                        }
                        break;
                    case '2':
                        if(flag_menu==0) {
                            credits();
                        }
                        break;
                        case '3':
                            if(flag_menu==0) {
                                log_stat = 2;
                                log_out();
                            }
                            break;
                        case 27:
                                if(flag_menu==1 || flag_menu==3 || flag_menu==3 || flag_menu==9) {
                                    to_tray = 4;
                                } else
                                if(flag_menu == 0) {
                                    to_tray = 1;
                                }
                            break;
                        case 'h':
                            help_window();
                            break;
                        case 't':
                            to_tray=1;
                            break;

                        default:
                            break;
                }
                // yaha ko to_tray value service menu bata auchha
                if(to_tray == 3) {
                    help_window();
                } else
                if(to_tray == 1) {
                    break;
                } else
                if(to_tray ==4) {
                    show_menu();
                }
                if (log_stat==2) { break;}
        }
        if(log_stat == 2) { goto start_log;}
        if(to_tray==1) {goto start_menu;}
return 0;
}
