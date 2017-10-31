
/*
	File:- config.h
	Desc:- contains all the variable declarations,functions declarations,constans definition...
*/

#include <stdio.h>  //Provides the core input and output capabilities of the C language.
#include <conio.h>  //for doing console input output
#include <ctype.h> //Contains functions used to classify characters by their types or to convert between upper and lower case in a way that is independent of the used character set
#include <stdlib.h> //For performing a variety of operations, including conversion, pseudo-random numbers, memory allocation, process control, environment, signalling, searching, and sorting.
#define _WIN32_WINNT 0x0500 //constant for console resizing (redifinition)
#include <windows.h> //defines a very large number of Windows specific functions that can be used in C.
#include <string.h> //For manipulating several kinds of strings.
#include <time.h> //For converting between various time and date formats.
#include <winsock2.h>   // contains functions for socket programmming
#include <process.h>
#define DEFAULT_PORT 5000
#define STRLEN 256
#define NUM_CLIENTS 10
#define MAX_SERVICES 10
#define NUM_MSG 4  //number of fields in protocol

//keys define
#define F1    59   //Client 1
#define F2    60 //Client 2
#define F3    61  //Client 3
#define ESC    37  //Escape key
#define ALT_A     30

//Threading Handles declaration
HANDLE handleAccept,handleMessages,clientHandle,HandleClients[NUM_CLIENTS];
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);

int flag_menu=0;
int no_of_clients = 0;
int no_of_msgs = 0;
char recMessage[STRLEN];
char sendMessage[STRLEN];

bool done = false;  //if it is true, the communication ends
SOCKET Socket;

extern "C" WINBASEAPI HWND WINAPI GetConsoleWindow (void);

struct cTime{
    int hr,min;
}logIn,logOut,reqTime[MAX_SERVICES];


//Service request Struture
struct request{
    int num_request;
    //char service[MAX_SERVICES][STRLEN];
    int service_id[MAX_SERVICES];
    int no_of_services;
    struct cTime reqTime[MAX_SERVICES];
};

struct client
{
    int id;
    sockaddr_in c_address;
    int c_addr_len;
    SOCKET c_socket;
    bool connected;
    bool turn;
    struct request r;
    struct cTime logIn;
    struct cTime logOut;
    int cost;
    bool active;
};
struct client c[NUM_CLIENTS]; //struct client c[n]; if multiple clients

int clients[NUM_CLIENTS];
COORD coord = {0, 0}; // sets coordinates to 0,0
bool SOCKET_START = false;  //TRUE if socket is already initialised
bool login_server = false;  // TRUE if server is alerady logged in

time_t t;  // structure for accessing system time

char *client_ip_address;
char *program_msg[STRLEN];
char cyberName[50];

extern "C" WINBASEAPI HWND WINAPI GetConsoleWindow (void);

//Global variables


//Function declarations
void main_menu();  //Main interface of the system
void gotoxy(int x,int y); //jump to coordinates
void delay(unsigned int mseconds); //create a delay
int get_code(void);  //get current key code of enterted key


//Utility functions
void readMessage(int msgExtracted[NUM_MSG],char username[20],char password[20],char msg[STRLEN]); //read message from client and extract
void clearArea(int left,int top,int right,int bottom);  //Clears the certain area of screen with whitespaces
void message_display(char* msg[STRLEN],int disType);
int findStrArrLen(char* str[STRLEN]);
void intToString(int n,char str[]);  //convert int string
void readTime(int timeExtracted[2],char timeString[10]);
void systemTime(char Ms[20]);
void getTime(int x[2]);
void getDate(char sDate[13]);
void newMessage(char msg[]);  //Increments the messages
bool send_to_network(char *buffer,int client_id);
//Server client related functions
void start_socket();
void start_server();

//bool send_data(char *);void disconnect_client(int);
void shutdown_server();
void echo_message( char *message );
void send_data( client *temp, char *buffer, int size );
bool s_recv_data( char *buffer,int client_id);
bool recv_from_network( char *buffer);
bool send_to_network(char *buffer);

void send_services_list(int client_no);  //send services list to client if requested
//Server InterFace Part
bool flag_gotoxy;   //checks if the gotoxy is busy or not  true=busy , false = free
bool flag_clear;  //true = clear  false= no action
bool flag_newMsg;
bool flag_reset;   //if server resetes this flag, all disconnected clients are cleared up
void gotoPrint(int x, int y,char msg[STRLEN]);
void show_admin();

//Threads
//void message_display(void *param,int disType);
void clients_table(void *param);
void thd_start_client_thread(void *param);
void thd_accept_connections(void *param);
void thd_receive_data(void *param);
void thd_program_messages(void *param);

//Admin Function part

FILE *login;  /* file pointer for login process */
FILE *fcost; /* file pointer for cost of login time*/
FILE *fp;      /* file pointer for id , price, qty etc of the services */
//structure
struct userlogin
{
    char username[25];
    char password[25];
    int flag_admin;
};
struct userlogin login1;

struct cost_mem
    {
        //int count;
        //float time[10];
        int rate;
        //float rate[10];
    };
struct cost_mem cost1;

struct service_mem
{
    int item_id;
    char item_name[25];
    int item_price;
    int item_qty;
};
struct service_mem service1;

//decelaration of functions
char* password(void);
void member_settings_signup();
void member_settings_signin(void);
int check_username(char username[25]);
void main_menu(void);
void main_lomenu(void);
void settings(void);
void requests();
void cost(void);
void setcost(void);
void viewcost(void);
void admin_settings();
void admin_settings_signup();
void admin_settings_signin();
void change_password();
void services();
void add_services();
void edit_services();
void view_services();
void delete_services();
void search_services();
int check_item_id(int id);
void window();
char* getServiceName(int s_id);
int getRate();
void requests();
int checkUser(char username[20],char password[20]);
int getNumServices();
void decServiceQty(int ser_id);

//interface.h
void console_settings();
void console_resize(int new_x, int new_y);
void reset_console();
