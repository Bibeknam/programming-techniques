/*
	File:- sock.h
	Desc:- contains the socket related functions
*/


bool c_send_data(char *buffer){
    if(send( Socket, buffer, STRLEN, 0)== SOCKET_ERROR){
        printf("couldnot send");
    }
    return true;
}

bool c_recv_data( char *buffer){
    int i = recv( Socket, buffer, STRLEN, 0 );
    buffer[i] = '\0';
   return true;
}


void connect_server(){
    sockaddr_in cl_address;
    fflush(stdin);
    //char ipaddress[50];
    int port;
    //char ipaddress[50] = "127.0.0.1";
    //printf("\nEnter ipAddress of server:- ");
    //gets(ipaddress);
   // printf("Enter port number:- ");
   // scanf("%d",&port);
    fflush(stdin);
    port = port_add;
    cl_address.sin_family=AF_INET;
    cl_address.sin_addr.s_addr=inet_addr(ipaddress);
    cl_address.sin_port=htons(port);
    if(connect(Socket,(sockaddr *) &cl_address,sizeof(cl_address))==SOCKET_ERROR){
        printf("\n\aError connecting to server\a\n");
        system("pause");
        WSACleanup();
        //exit(1);
        client();
    }
    else
        printf("\nConnected to server\n");
        //c_send_data("4:2:0:4:");
    //system("pause");
}

void start_socket()
{
    WSADATA wsadata;   //initiate the use of ws2_32.dll
    if(WSAStartup(MAKEWORD(2,0),&wsadata)!=0)   //MAKEWORD(2,0) makes request for version 2.0 of winsock on system
    {
        printf("Socket Initialization: Error with WSAStartup \n required version snot availabel \n");
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
        printf("Socket Initialization: Error creating socket\n");
        system("pause");
        WSACleanup();
        exit(11);
    }
    else
        printf("socket initialised");

}
