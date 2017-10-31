#include "var.h"
#include "window_function.h"

int check_array(int key, int Q_No){
    int i;
    for(i = 0; i < Q_No; i++){
        if(array[i] == key)
        return 0;
    }
    return 1;
}

int randomize(int Q_No){
    FILE *fp;
    int random,n;
    fp = fopen("Questions/Questions.txt","rb");
    n = increase_question();
    while(1){
        rewind(fp);
        srand(time(NULL));
        random = rand()%n;
        while(random == 0 )
            random = rand()%n;
        while(fread(&Q,sizeof(Q),1,fp) == 1){
            if(random == Q.id){
                if(check_array(random,Q_No)!=0){
                    array[Q_No - 1] = random;
                    return random;
                }else{
                    break;
                }
            }
        }

    }
}

int ask_Question(struct Quiz temp){
    char ch;
    int op;
    gotoxy(10,15);
    puts(temp.question);
    gotoxy(10,19);printf("1. ");
    puts(temp.op1);
    gotoxy(50,19);printf("2. ");
    puts(temp.op2);
    gotoxy(10,23);printf("3. ");
    puts(temp.op3);
    gotoxy(50,23);printf("4. ");
    puts(temp.op4);
    ch = getch();
    op = (int)ch - 48;
    while(op > 4 || op < 1 ){
        MessageBox(0,"Enter 1, 2, 3 or 4 only","Warning ",0);
        ch = getch();
        op = (int)ch - 48;

    }
    return op;
}

void Increase_Prize(int id){
    if(id == 1){
        writeLevel(1);
        prize = 1000;
    }else if(id == 2){
        writeLevel(2);
        prize = 2000;
    }else if(id == 3){
        writeLevel(3);
        prize = 5000;
    }else if(id == 4){
        writeLevel(4);
        prize = 10000;
    }else if(id == 5){
        writeLevel(5);
        prize = 50000;
    }else if(id == 6){
        writeLevel(6);
        prize = 100000;
    }else if(id == 7){
        writeLevel(7);
        prize = 500000;
    }else if(id == 8){
        writeLevel(8);
        prize = 1000000;
    }
}

void write_congrats(){
    int i;
    gotoxy(7,10);
    for(i = 0; massege[i]!='\0'; i++){
        SetColor(14);
        Sleep(100);
        printf("%c",massege[i]);
    }
    ClearColor();
    gotoxy(12,11);
    printf("You Win: %d",prize);
    Sleep(3000);
    gotoxy(7,10);
    for(i = 0; massege[i] != '\0'; i++){
        printf(" ");
    }
    gotoxy(12,11);
    for(i = 0; i < 20; i++){
        printf(" ");
    }
}

void Write_sory_and_prize(){
    system("cls");
    gotoxy(30,10);
    SetColor(12);
    printf("Sorry! Your Answer was wrong");
    gotoxy(30,11);
    SetColor(11);
    printf("Thank you for participation.");
    gotoxy(37,12);
    ClearColor();
    printf("You Win : %d", prize);
    Sleep(5000);
    return;

}

void writefinalcongrats(){
    system("cls");
    gotoxy(30,10);
    SetColor(18);
    printf("Congratulation! Your are the winner");
    gotoxy(37,11);
    SetColor(11);
    printf("You Win: %d",prize);
    gotoxy(30,12);
    ClearColor();
    printf("Thank you for participation");
    Sleep(5000);
}

int check_ans(int q,int a){
    FILE *fp;
    fp = fopen("Questions/Questions.txt","rb");
    while(fread(&Q,sizeof(Q),1,fp)){
        if(q == Q.id && a == Q.correctAns){
            return 1;
        }
    }
    return 0;
}


int increase_question(){
    FILE *qp;
    int count = 0;
    qp = fopen("Questions/Questions.txt","rb+");
    while(fread(&Q,sizeof(Q),1,qp)==1){
    }
    return Q.id+1;
}

void Add_Questions(){
    FILE *fp;
    int Q_No;
    char another = 'y';
    fp = fopen("Questions/Questions.txt","ab+");
    if(fp == NULL){
        printf("Error in creating/opening file");
    }
    while(another == 'y'){
        system("cls");
        Q_No = increase_question();
        Q.id = Q_No;
        gotoxy(5,5);
        printf("Enter Question No %d: ",Q_No);
        fflush(stdin);
        gets(Q.question);
        gotoxy(5,6);
        printf("Option 1: ");
        gets(Q.op1);
        gotoxy(25,6);
        printf("Option 2: ");
        gets(Q.op2);
        gotoxy(5,7);
        printf("Option 3: ");
        gets(Q.op3);
        gotoxy(25,7);
        printf("Option 4: ");
        gets(Q.op4);
        gotoxy(5,8);
        printf("Correct Ans: ");
        scanf("%d",&Q.correctAns);
        fseek(fp,0,SEEK_END);
        fwrite(&Q,sizeof(Q),1,fp);
        fclose(fp);
        gotoxy(5,9);
        printf("add another(y/n) ");
        another = getche();
    }
}

void modify_question(){
    system("cls");
    FILE *fp;
    int Q_No;
    int isFound = 0;
    fp = fopen("Questions/Questions.txt","rb+");
    if(fp == NULL){
        printf("Error in opening file");
        return;
    }
    gotoxy(5,4);
    printf("Enter the Qusetion no to modify: ");
    scanf("%d",&Q_No);
    while(fread(&Q,sizeof(Q),1,fp) == 1){
        if(Q_No == Q.id){
            gotoxy(5,5);
            printf("Enter New Question: ");
            fflush(stdin);
            gets(Q.question);
            gotoxy(5,6);
            printf("Option 1: ");
            gets(Q.op1);
            gotoxy(35,6);
            printf("Option 2: ");
            gets(Q.op2);
            gotoxy(5,7);
            printf("Option 3: ");
            gets(Q.op3);
            gotoxy(35,7);
            printf("Option 4: ");
            gets(Q.op4);
            gotoxy(5,8);
            printf("Correct Ans: ");
            scanf("%d",&Q.correctAns);
            fseek(fp,ftell(fp)-sizeof(Q),0);
            fwrite(&Q,sizeof(Q),1,fp);
            isFound = 1;
            break;
        }
    }
    if(isFound ==0 ){
        gotoxy(5,6);
        printf("No record found!");
    }
    gotoxy(5,9);
    printf("Press any key.....");
    fclose(fp);
    getch();

}

void delete_question(){
    system("cls");
    FILE *fp, *temp;
    int Q_No;
    int isFound = 0;
    fp = fopen("Questions/Questions.txt","rb+");
    if(fp == NULL){
        printf("Error in opening file");
        return;
    }
    gotoxy(5,4);
    printf("Enter the Qusetion no to delete: ");
    scanf("%d",&Q_No);
    temp = fopen("Questions/temp.txt","wb");

    while(fread(&Q,sizeof(Q),1,fp) == 1){
        if(Q_No != Q.id){
            fwrite(&Q,sizeof(Q),1,temp);
        }
    }
    fclose(fp);
    fclose(temp);

    remove("Questions/Questions.txt");
    rename("Questions/temp.txt","Questions/Questions.txt");
    gotoxy(5,9);
    printf("Press any key.....");
    fclose(fp);
    getch();

}

void clear_area(){
    int i;
    gotoxy(6,19);
    for(i = 0; i < 24; i++){
        printf(" ");
    }
    gotoxy(46,19);
    for(i = 0; i < 24; i++){
        printf(" ");
    }
    gotoxy(6,23);
    for(i = 0; i < 24; i++){
        printf(" ");
    }
    gotoxy(46,23);
    for(i = 0; i < 24; i++){
        printf(" ");
    }
    gotoxy(6,15);
    for(i = 0; i < 60; i++){
        printf(" ");
    }

}


void check_keyboard(int num){
    if(num == 80){
        main_window++;
        if(main_window > 3){
            main_window = 3;
            printf("\a");
        }
    }else if(num == 72){
        main_window--;
        if(main_window < 1){
            main_window = 1;
            printf("\a");
        }
    }
}
