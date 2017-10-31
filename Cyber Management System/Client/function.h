/*
	File:- function.h
	Desc:- contains all the functions related to menu control,server and client interfacing
*/
#include "config.h"
#include "sock.h"
#include "interface.h"


void show_time(void *param) {
    long i = 0;                      /* Loop counter              */
                     /* Holds initial clock time  */
    int interval = 1;                /* Seconds interval for o/p  */
    int elapsed = 0;
    int min=0,MIN=0,hrs=0,sec=0;
    int d=0,f=0;
    //now = clock(); /* Get current clock time    */
    int pos=2;

    for(i = 0 ;  ; i++)
    {
     // if(log_stat==0) {break;}
      //elapsed = (clock()-now)/CLOCKS_PER_SEC;

      if(i%60==0)
      {

           min=i/60;
           d=60*min;
                if(min%60==0)
            {
                hrs=min/60;
                f=60*hrs;
            }
        }
        sec=i-d;
        MIN=min-f;
         if(hrs<10)
        {
            gotoxy(7,pos);printf("0%d",hrs);
            }
        else
        {
            gotoxy(7,pos);printf(":%d",hrs);
            }
        if(min<10)
        {
            gotoxy(9,pos);printf(":0%d",MIN);
            }
        else
        {
            gotoxy(9,pos);printf(":%2d",MIN);
            }

        if(sec<10)
        {
            gotoxy(12,pos);printf(":0%d",sec);
        }
        else
        {
            gotoxy(12,pos);printf(":%2d",sec);
        }
             if(MIN==0 && sec == 2) {
                cost_changed = fixed_rate/4;
            } else if(MIN ==15 && sec == 0) {
                cost_changed = fixed_rate/4;
            } else if(MIN == 30 && sec == 0) {
                cost_changed = fixed_rate/2;
            }

         if (log_stat==2) {break;}
         if(cost_changed != 0) {
                tot_cost += cost_changed;
            }
            cost_changed = 0;
            gotoxy(28,2);printf("Rs.%d",tot_cost);
         delay(1000);
    }
    _endthread();
}


void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
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
               /* Return the string */
}



//this function resets all the variables to null before sending!!
void reset_variables() {
    service_id = 0;
    is_member = 0;
    strcpy(username,"");
    strcpy(password,"");
    fixed_rate;
    tot_service;
    cost_changed=0;
    check_flag = 0;
    tot_cost=0;
    to_tray = 1;
}

void get_password(char* pass)
{
    char temp_passP[25];
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
                } else {printf("\a");}
            }
            else
            {
                printf("*");
                *(pass+i) = temp_passP[i];
                i++;
            }
             *(pass+i)='\0';
     }
}

bool confirm_member() {
    char Message[STRLEN],repMessage[STRLEN];
    createMessage(Message);
    c_send_data(Message);
    c_recv_data(repMessage);
    if(repMessage[0] == '1') {
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
        return true;
    } else { return false;}

}

char* createMessage(char Message[]) {
    char a[3],b[3],c[3],cost[6];
    intToString(computer_id,Message);
    intToString(service_id,a);
    intToString(log_stat,b);
    intToString(is_member,c);
    //printf(":::%s-%d-%s:::",a,log_stat,c);

    //creating message to be sent
    strcat(Message,":");
    if (atoi(a) == 2){
        intToString(tot_cost,cost);
        strcat(Message,cost);
    } else {
        strcat(Message,a);
    }
    strcat(Message,":");
    strcat(Message,b);
    strcat(Message,":");
    strcat(Message,c);
    strcat(Message,":");
    if (!strcmp(username,"")) {
        strcat(Message,"0");
    } else {strcat(Message,username);}
    strcat(Message,":");
    if (!strcmp(password,"")) {
        strcat(Message,"0");
    } else {strcat(Message,password);}
    strcat(Message,":");

   // printf("\n%s",Message);getch();
    //creating message to be sent
    return Message;
}

int get_service_info() {
    char Message[STRLEN],repMessage[STRLEN],item[15],rate[4];
    log_stat = 3;
    createMessage(Message);
    c_send_data(Message);
    int a = 0;
    while(1) {
        c_recv_data(repMessage);
        for(i=0;repMessage[i]!=':';i++) {
            item[i] = repMessage[i];
        }
        item[i]='\0';
        i++;
        strcpy(items[a].name,item);

        for(j=i;repMessage[j]!=':';j++) {
            rate[j-i] = repMessage[j];
        }
        rate[j] = '\0';
        j++;
        items[a].rate = atoi(rate);

        char tmp_flag = repMessage[j];
        int flag = atoi(&tmp_flag);
        //printf("%s",items[a].name);getch();
        if(flag) { break;}
        a++;
        strcpy(item,"");
    }
    return (a+1); //returns the size of the array

}


void assign_ip_address(void)

    FILE *assignIp;
    assignIp=fopen("ip_add.dat","rb");
    if(ip==NULL)
    {
        printf("\nCan not open file");
        exit(1);
    }
    while(fread(&ip1,sizeof(ip1),1,assignIp)==1)
    {
        strcpy(ipaddress,ip1.ip_address);
        port_add=ip1.port_no;
        computer_id = ip1.client_no;
    }
    fclose(assignIp);
}


