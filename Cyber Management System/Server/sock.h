/*
	File:- sock.h
	Desc:- contains the socket related functions
*/

bool send_to_network(char *buffer,int client_id){
    if(send( c[client_id].c_socket, buffer, STRLEN, 0 )== SOCKET_ERROR){
        newMessage("Error Sending Data");
    }
   // gotoPrint(20,35,buffer);

    return true;

}


bool recv_from_network( char *buffer){
    int i = recv( Socket, buffer, STRLEN, 0 );
    buffer[i] = '\0';
   return true;
}
bool s_recv_data( char *buffer,int client_id){
    int i = recv( c[client_id].c_socket, buffer, STRLEN, 0 );
    buffer[i] = '\0';
   return true;
}

void disconnect_client(int x)
{
    if(c[x].connected==true)
    {
        // closesocket ( c[x].c_socket );
         char ClMsgs[30],str[5];
        newMessage("A client Logs out.");
        /*intToString(client_id,str);
        strcpy(ClMsgs,"Client no. ");
        strcat(ClMsgs,str);
        strcat(ClMsgs," log outs.");
        newMessage(ClMsgs);
        */
        c[x].active=false;
        //gotoPrint(10,30,ClMsgs);
        //newMessage(ClMsgs);
        //c[x].c_addr_len=-1;
        //no_of_clients--;
    }
    else
        printf("\ncouldnt disconnect client:");
}

//start server ....bind port,,,,,and listen to incoming connections
void start_server(){
    newMessage("Startig Server");
    sockaddr_in	server_address;
    server_address.sin_family=AF_INET;
    server_address.sin_addr.s_addr=inet_addr("0.0.0.0");
    server_address.sin_port=htons(DEFAULT_PORT);

    if(bind(Socket,(sockaddr *) &server_address,sizeof(server_address))==SOCKET_ERROR)
    {
        newMessage("Failed to bind the socket");
        system("pause");
        WSACleanup();
        exit(11);
    }
   else{
        *(program_msg+no_of_msgs++) = "Socket Binded";
        flag_newMsg = true;
   }


    //listening the clients
    if(listen(Socket,1)==SOCKET_ERROR)
    {
        newMessage("error listening on socket");
        system("pause");
        WSACleanup();
        exit(0);
    }
    else
       newMessage("Ready to accept Connections");


}

//initialisation of windows socket
void start_socket()
{
    WSADATA wsadata;   //initiate the use of ws2_32.dll
    if(WSAStartup(MAKEWORD(2,0),&wsadata)!=0)   //MAKEWORD(2,0) makes request for version 2.0 of winsock on system
    {
        newMessage("Socket Initialization: Error with WSAStartup required version snot available");
        system("pause");
        WSACleanup();  //release resources
        exit(10);
    }
    //creation of socket
    Socket=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    /*
        AF_INET- specify the IPv4 address family.
        SOCK_STREAM - specify a stream socket.
        IPPROTO_TCP - specify the TCP protocol .

    */
    if (Socket==INVALID_SOCKET)
    {
        newMessage("Socket Initialization: Error creating socket");
        system("pause");
        WSACleanup();
        exit(11);
    }
    else
        newMessage("Socket Initialised");
}
