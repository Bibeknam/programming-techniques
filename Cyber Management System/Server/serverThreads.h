/*
* serverThreads.h
* Contains all the server related threads
* @author: <base-2>
* Date:- 9-11-2010
*/

void thd_receive_data(void *param){
    int i,j,cMsg[NUM_MSG],client_id,login_status,num_req,ser_id,clTime[2],isMember,memberType,rate;
    FILE *sLogin;
    int count = 9;
    j = *((int*)param);
    j-=1;
    //gotoxy(20,30); printf("%d",j);
    //getch();
    char Msgs[20],username[20],password[20],sendData[50],rates[5];
    char str[10];
        while(1){
               // printf("::%d||%d",c[j].connected,j);
                if(c[j].connected){
                    //MessageBox(0,"Receive","Receive Data",0);
                    i=recv(c[j].c_socket,recMessage,STRLEN,0);
                    //gotoxy(20,40); puts(recMessage);
                    if(i != SOCKET_ERROR){
                        //MessageBox(0,"Receive","Receive Data",0);
                        readMessage(cMsg,username,password,recMessage);
                        client_id = cMsg[0];
                        ser_id = cMsg[1];
                        login_status = cMsg[2];
                        isMember = cMsg[3];
                        if(client_id!=0){
                            if(login_status == 0){  //just connected
                                if(isMember == 1)
                                    memberType = checkUser(username,password); //1 ok 0 no
                                if(memberType == 1 || isMember == 0){  //0 - guest
                                    c[j].r.num_request = 0;
                                    c[j].cost = 0;
                                    c[j].active=true;
                                    if(memberType == 1)
                                        intToString(memberType,sendData);
                                    else
                                        intToString(isMember,sendData);
                                    rate = getRate();
                                    intToString(rate,rates);
                                    strcat(sendData,":");
                                    strcat(sendData,cyberName);
                                    strcat(sendData,":");
                                    strcat(sendData,rates);
                                    strcat(sendData,":");
                                    c[j].id = client_id;
                                    send_to_network(sendData,j);
                                    intToString(client_id,str);
                                    strcpy(Msgs,"Client no. ");
                                    strcat(Msgs,str);
                                    strcat(Msgs," is logged in.");
                                    clients[no_of_clients] = client_id;
                                    gotoxy(7,count+j*2);
                                    printf("%d",client_id);
                                    c[j].r.num_request = 0;
                                    getTime(clTime);
                                    c[j].logIn.hr = clTime[0];
                                    c[j].logIn.min = clTime[1];
                                    gotoxy(45,count+j*2);
                                    printf("%d:%d",c[j].logIn.hr,c[j].logIn.min);
                                    newMessage(Msgs);

                                    main_menu();
                                }else{
                                    send_to_network("0",j); //no member
                                }

                        }
                        else if(login_status == 1){  //cyber running and client requests service
                            if(getNumServices() >= ser_id){ //if jpt service send
                                printf("\a");
                                char CMsgs[20] = "";
                                intToString(client_id,str);
                                strcpy(CMsgs,"Client no. ");
                                strcat(CMsgs,str);
                                strcat(CMsgs," requested for a service.");
                                num_req = c[j].r.num_request;
                                c[j].r.num_request++;
                                c[j].r.service_id[num_req] = ser_id;
                                gotoxy(30,count+j*2);
                                printf("%d",c[j].r.num_request);
                                decServiceQty(ser_id);
                                getTime(clTime);
                                c[j].r.reqTime[num_req].hr = clTime[0];
                                c[j].r.reqTime[num_req].min = clTime[1];
                                strcpy(sendData,"1:");
                                send_to_network(sendData,j);
                                newMessage(CMsgs);
                            }else{ //the item is not available
                                send_to_network("0",j);

                            }
                        }
                        else if(login_status == 2){  //log outs
                            c[j].logOut.hr = clTime[0];
                            c[j].logOut.min = clTime[1];
                            c[j].cost = cMsg[1];
                            gotoxy(60,count+j*2);
                            printf("%d:%d",c[j].logOut.hr,c[j].logOut.min);
                            gotoxy(75,count+j*2);
                            printf("Rs. %d",c[j].cost);
                            disconnect_client(j);   //log outs
                            //newMessage(ClMsgs);
                        }
                        else if(login_status == 3){  //give all the service menu to clients
                            send_services_list(j);
                        }
                    }
                    }
                }

        }
_endthread();
}


//Print the messages from clients
void thd_program_messages(void *param){
    int c,i;
    while(1){
        c = 2;
        Sleep(100);  //check in interval 0f 0.1s
        if(flag_newMsg == true && flag_menu ==0){
              //check in interval 0f 0.1s
            gotoPrint(95,c,"Messages:-");
            //int msgLength = findStrArrLen(program_msg);
            for(i = no_of_msgs-1; i>=0 ;i--){
                if(i<no_of_msgs-25)
                  break;
                Sleep(100);
                c+=2;
                flag_gotoxy = false;
                gotoxy(95,c); printf("                                                         ");
                gotoPrint(95,c,*(program_msg+i));
            }
            flag_newMsg = false;
        }

    }
    _endthread();
}


//accept connections from new client
void thd_accept_connections(void *param)
{
 int i;
 while(no_of_clients != NUM_CLIENTS) //accept connections until all get connected
    {
        i = no_of_clients;
        c[i].c_addr_len=sizeof(c[i].c_address);
        c[i].c_socket=accept(Socket,(sockaddr *) &(c[i].c_address),&c[i].c_addr_len);
        if(c[i].c_socket==SOCKET_ERROR)
            printf("couldnt accept connections");
        else{  //client connected
            //char *client_ip_address = inet_ntoa ( c[i].c_address.sin_addr );
             c[i].r.num_request = 0;
             c[i].cost = 0;
             c[i].connected=true;

             //Create a new thread for the client
             HandleClients[i] =(HANDLE) _beginthread(thd_receive_data,0,&i);
             no_of_clients++;


             //MessageBox(0,"Client Connected","Accepted",0);

        }
    }
_endthread();
}
