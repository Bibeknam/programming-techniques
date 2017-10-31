#include<windows.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

long int prize = 0;
char massege[] = "Congratulation! Correct Answer";
int array[8] = {0,0,0,0,0,0,0,0};
int main_window = 1;

struct Quiz{
    int id;
    char question[50];
    char op1[20];
    char op2[20];
    char op3[20];
    char op4[20];
    int correctAns;
};
struct Quiz Q;
