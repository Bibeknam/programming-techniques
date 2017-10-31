#include "admin.h"

void call_window(){
    writeLogo("Programming Techniques Quiz\n\t\tCompitition");
    writeLevel(0);
    drawWindow();
}

void User_Mode(){
    system("cls");
    FILE *fp;
    int ch, Ans_No;
    int Q_No = 0,q_no;
    SetConsoleTitle("programming-technique.blogspot.com - Quiz");
    call_window();
    fp = fopen("Questions/Questions.txt","rb");
    while(1){
        Q_No++;
        if(Q_No > 8){
            writefinalcongrats();
            fclose(fp);
            break;
        }
        q_no = randomize(Q_No);
        fseek(fp,q_no,SEEK_SET);
        Ans_No = ask_Question(Q);
        if(check_ans(Q.id,Ans_No) == 1){
            Increase_Prize(Q_No);
            write_congrats();
            clear_area();
        }else{
            Write_sory_and_prize();
            break;
        }
    }
    return;

}

void admin_Mode(){
    while(1){
        system("cls");
        gotoxy(30,10);
        printf("1. Add Questions ");
        gotoxy(30,12);
        printf("2. Modify Questions ");
        gotoxy(30,14);
        printf("3. Delete Questions ");
        gotoxy(30, 16);
        printf("4. Back ");
        gotoxy(30, 18);
        printf("Enter your Choice: ");
        switch(getch()){
            case '1':
                Add_Questions();
                break;
            case '2':
                modify_question();
                break;
            case '3':
                delete_question();
                break;
            case '4':
                return;
        }
    }
}

int main(){
    char ch;
    ClearConsoleToColors(15,1);
    SetConsoleTitle("programming-technique.blogspot.com - Quiz");
    while(1){
        system("cls");
        gotoxy(30,10);
        if(main_window == 1) SetColorAndBackground(15,12);
        else SetColorAndBackground(15,1);
        printf("PLAY GAME - USER MODE");
        gotoxy(30,12);
        if(main_window == 2) SetColorAndBackground(15,12);
        else SetColorAndBackground(15,1);
        printf("ADMINSTRATOR MODE");
        gotoxy(30, 14);
        if(main_window == 3) SetColorAndBackground(15,12);
        else SetColorAndBackground(15,1);
        printf("QUIT GAME");
        SetColorAndBackground(15,1);
        ch = getch();
        check_keyboard((int)ch);
        if((int)ch == 13){
            switch(main_window){
                case 1:
                    User_Mode();
                    break;
                case 2:
                    admin_Mode();
                    break;
                case 3:
                    exit(0);
            }
        }
    }
    return 0;
}
