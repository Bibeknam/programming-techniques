#include "color_function.h"

COORD xy = {0,0};
void gotoxy (int x, int y)
{
        xy.X = x; xy.Y = y; // X and Y coordinates
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}

void drawRectangle(int x1, int y1, int x2, int y2){
    int i, j;
    gotoxy(x1,y1);
    printf("%c",201);
    for(i = x1; i < x2; i++){
        gotoxy(i+1, y1);
        printf("%c",205);
    }
    gotoxy(x2,y1);
    printf("%c",187);
    for(i = y1; i < y2; i++){
        gotoxy(x2, i+1);
        printf("%c",186);
    }
    gotoxy(x2, y2);
    printf("%c",188);
    for(i = x2; i > x1; i--){
        gotoxy(i-1,y2);
        printf("%c",205);
    }
    gotoxy(x1,y2);
    printf("%c",200);
    for(i = y2; i > y1+1; i--){
        gotoxy(x1,i-1);
        printf("%c",186);
    }
    gotoxy(x1,y2+1);
}

void drawWindow(){
    drawRectangle(5,17,30,20);
    drawRectangle(5,21,30,24);
    drawRectangle(45,17,70,20);
    drawRectangle(45,21,70,24);
    drawRectangle(5,13,70,16);
    drawRectangle(2,2,75,25);
}


void writeLogo(const char logo[]){
    gotoxy(10, 5);
    SetColor(10);
    printf("%s",logo);
    ClearColor();
}

void writeLevel(int level){
    gotoxy(55,11);
    if(level == 1) SetColorAndBackground(15,12);
    else SetColorAndBackground(15,1);
    printf("%c Rs.1,000",4);
    gotoxy(55,10);
    if(level == 2) SetColorAndBackground(15,12);
    else SetColorAndBackground(15,1);
    printf("%c Rs.2,000",4);
    gotoxy(55,9);
    if(level == 3) SetColorAndBackground(15,12);
    else SetColorAndBackground(15,1);
    printf("%c Rs.5,000",4);
    gotoxy(55,8);
    if(level == 4) SetColorAndBackground(15,12);
    else SetColorAndBackground(11,1);
    SetColor(11);
    printf("%c Rs.10,000",4);
    gotoxy(55,7);
    if(level == 5) SetColorAndBackground(15,12);
    else SetColorAndBackground(15,1);
    printf("%c Rs.50,000",4);
    gotoxy(55,6);
    if(level == 6) SetColorAndBackground(15,12);
    else SetColorAndBackground(11,1);
    printf("%c Rs.100,000",4);
    gotoxy(55,5);
    if(level == 7) SetColorAndBackground(15,12);
    else SetColorAndBackground(15,1);
    printf("%c Rs.500,000",4);
    gotoxy(55,4);
    if(level == 8) SetColorAndBackground(15,12);
    else SetColorAndBackground(11,1);
    printf("%c Rs.1,000,000",4);
    SetColorAndBackground(15,1);
}

