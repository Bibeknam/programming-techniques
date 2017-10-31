/*
	File:- function.h
	Desc:- contains all the functions related to menu control,server and client interfacing
*/
#include "config.h"
#include "sock.h"
#include "admin_function.h"
#include "interface.h"
#include "serverThreads.h"



/*
* C.yber Protocol
* Date: September 10,2010
* @author: <base-2> team
* Transfer Rule:- (Computer-id:service_id:status:isMember:username:password) sent by client as a single string
*/

void readMessage(int msgExtracted[NUM_MSG],char username[20],char password[20],char msg[STRLEN]){
    printf("\a");
    int i = 0,j = 0,k=0;
    char msgExt[20];
    do{
        msgExt[j] = msg[i];
        if(msg[i] == ':' || msg[i] == '\0'){

                msgExt[j] = '\0';

                if(k==4)
                    strcpy(username,msgExt);
                else if(k==5){
                    strcpy(password,msgExt);
                    break;
                }
                else
                    msgExtracted[k] = atoi(msgExt);

                j = 0; //reset
                if(msg[i] != '\0'){
                    i++; k++;
                }
        }
        else{
            i++;
            j++;
        }
    }while(msg[i] !='\0');


}


int get_code(void)
{
 char key;
  if((key=getch())==0)
   return(getch());
  else if(key=='\r')
   return(key);
   else if(key==ESC)
    return(key);
  else if(key==getch())
    return (key);
  else
   return (0);

} //end of get_code()

void intToString(int n, char str[])
{
  int i = 0;               /* Loop counter              */
  int negative = 0;        /* Indicate negative integer */
  int temp = 0;            /* Temporary storage         */

  if(negative = (n<0))     /* Is it negative?  */
    n = -n;                /* make it positive */

  /* Generate digit characters in reverse order */
  do
  {
    str[i++] = '0'+n%10;    /* Create a rightmost digit        */
    n /= 10;                /* Remove the digit                */
  }while(n>0);              /* Go again if there's more digits */

  if(negative)              /* If it was negative */
    str[i++] = '-';         /* Append minus       */
  str[i] = '\0';            /* Append terminator  */

    str = strrev(str);   //reverse the string

  //return str;                /* Return the string */
}

void gotoxy (int x, int y)
{
        coord.X = x; coord.Y = y; // X and Y coordinates
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}


void clearArea(int left,int top,int right,int bottom){
    flag_gotoxy = true;
    flag_clear = true;
    int i,j;
    if(flag_clear == true){
        for(j=top;j<=bottom;j++){
                for(i = left;i<=right;i++){
                   // gotoPrint(i,j," ");
                   gotoxy(i,j); printf(" ");
                }
        }
    }
    flag_clear = false;
    flag_gotoxy = false;
}




// prints by checking flag_gotoxy
void gotoPrint(int x,int y,char msg[STRLEN]){
    //while(1){  //printf iff flag_busy is true
    flag_gotoxy = false;
        if(flag_gotoxy== false){
            gotoxy(x,y); printf("%s",msg);
        }
    flag_gotoxy = true;
    //}
}



void readTime(int timeExtracted[2],char timeString[10]){
    int i = 0,j = 0,k=0;
    char msgExt[20];
    do{
        msgExt[j] = timeString[i];
        if(timeString[i] == ':' ||timeString[i] == '\0'){
            msgExt[j] = '\0';
            timeExtracted[k] = atoi(msgExt);
            j = 0; //reset
            if(timeString[i] != '\0'){
                i++; k++;
            }
        }
        else{
            i++;
            j++;
        }
    }while(timeString[i] !='\0');


}

void systemTime(char Ms[10]) //for time
{
    int i,j=0,k=0,x;
	time_t t;
	time(&t);
	char tim[200];
	strcpy(tim,ctime(&t));
	for(i = 0; tim[i]!='\0';i++){
        if(tim[i]==':'){
            x = i-2;
            for(j=0;j<5;j++){
                Ms[k] = tim[x];
                k++;
                x++;
            }
            break;
        }
	}
    Ms[j] = '\0';

}

void getTime(int x[2]){
    int i;
    char Mss[10];
    systemTime(Mss);
    strcat(Mss,":");
    readTime(x,Mss);
}

void getDate(char sDate[13]){
    time_t now;
    struct tm *d;
    time(&now);
    d = localtime(&now);
    strftime(sDate, 15, "%d-%m-%Y", d);
}

void newMessage(char msg[]){
   //sTime = "asf";
    //strcat(sTime,msg);
    //strcat(msg,"->1:1");
    *(program_msg+no_of_msgs) = msg;
    no_of_msgs++;
    flag_newMsg = true;

}

void saveMessagesToFile(){
    FILE *fSave;
    int i;
    char fileLocation[30] = "save\\logs\\";
    char fileName[13];
    getDate(fileName);
    strcat(fileLocation,fileName);
    strcat(fileLocation,".txt");
    fSave = fopen(fileLocation,"a+");
    for(i = 0; i<no_of_msgs ;i++){
            fprintf(fSave,"%s\n",*(program_msg+i));
    }
    fclose(fSave);
}

int checkUser(char username[20],char password[20]){
    FILE *fCheck;
    fCheck=fopen("save\\logins.dat","rb");
    while(fread(&login1,sizeof(login1),1,fCheck)==1)
    {
        if((strcmp(login1.username,username)==0) && (strcmp(login1.password,password)==0))
         return 1;
    }
    return 0;
    fclose(fCheck);

}
int getRate(){
    FILE *fCost;
    fCost=fopen("save\\rate.dat","rb");
    while(fread(&cost1,sizeof(cost1),1,fCost)==1)
    {
        return cost1.rate;
    }
    fclose(fCost);
}

int getNumServices(){
    FILE *fService;
    int counter = 0;
    fService=fopen("save\\service.dat","rb");
     while(fread(&service1,sizeof(service1),1,fService)==1)
    {
        counter++;

    }
    fclose(fService);
    return counter;

}


void send_services_list(int client_no){
    FILE *fService;
    int no_of_services = getNumServices();
    char sendData[100],tempData[10];
    fService=fopen("save\\service.dat","rb");
     while(fread(&service1,sizeof(service1),1,fService)==1)
    {
        strcpy(sendData,service1.item_name);
        strcat(sendData,":");
        intToString(service1.item_price,tempData);
        strcat(sendData,tempData);
        strcat(sendData,":");
        if(no_of_services>1)
            strcat(sendData,"0");
        else
            strcat(sendData,"1");
        strcat(sendData,":");
        //gotoxy(20,40);  printf("%s",sendData);
        send_to_network(sendData,client_no);
        no_of_services--;
    }
    fclose(fService);

}
//Find Size of Array of String
int findStrArrLen(char* str[STRLEN]){
    int i;
    for(i=0;*(str+i) != NULL;i++);
    return i;
}

void decServiceQty(int ser_id){
FILE *fpQty;
fpQty=fopen("save\\service.dat","rb+");
 while(fread(&service1,sizeof(service1),1,fpQty)==1)
    {
        if(ser_id==service1.item_id)
        {
            service1.item_qty--;
            fseek(fpQty,-sizeof(service1),SEEK_CUR);
            fwrite(&service1,sizeof(service1),1,fpQty);
            fclose(fpQty);
            break;
        }
    }
}
