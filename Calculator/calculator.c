/************************************************************
Mini project on Scientific calculator

This project implements various mathematical operations in C
************************************************************/

/// list of header files
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/// list of global variables

struct Complex {
    float real;
    float imag;
};

struct Complex c1, c2, c3;


/// User defined function

/***********************************************
return the determinant term of quadratic equation
@param a highest order coeffcient
@param b lower order coefficient
@param c lowest coefficient
@return determinant term
************************************************/
float determinantTerm(float a, float b, float c)
{
    float temp = b*b - 4 * a * c;
    return temp;
}


/*********************************************
calculates the factorial of given integer
@param n input integer
@return factorial of n
***********************************************/

int factorial(int n){
    if (n == 0)
        return 1;
    else
        return n * factorial(n-1); /// recursive calculation
}


/**********************************************
calculates the sine of a given angle
@param angle given angle
@return sine value of angle
**********************************************/

float sine(float angle)
{
    int i;
    float radVal = angle * M_PI / 180.0;
    float result = 0;
    for (i = 1; i < 10; i++)
    {
        result += pow(-1,i-1) * pow(radVal, 2*i - 1) / factorial(2*i - 1);
    }
    return result;
}

float cosine (float angle){
    return 0; /// delete this
}

int main(){
    float a, b, c, dTerm, root1, root2;
    char choice, achoice;
    float angle, result;
    while(1){
        printf("\n*******************A Scientific Calculator*******************");
        printf("\nChoose the operations\n\n");
        printf("1. Matrix Operation\n");
        printf("2. Solution of non-linear poly equation\n");
        printf("3. Trigonometric calculation\n");
        printf("4. Solution of simultaneous equations\n");
        printf("5. Complex number operations\n");
        printf("6. Exit\n\n");
        printf("Enter your choice: ");
        scanf("\n%c", &choice);
        switch(choice){
        case '1':
            // IMPLEMENT IT
            printf("Here you will implement matrix operations");
            break;
        case '2': /// calculate the roots of quadratic equation
            
            printf("Enter a, b and c: ");
            scanf("%f %f %f", &a, &b, &c);
            dTerm = determinantTerm(a, b, c);
            /// if dTerm is positive, real root
            if(dTerm == 0)
            {
                printf("\nThe given equation has real and equal roots\n");
                printf("Both roots are %f", (-b)/(2*a));
            }
            else if(dTerm > 0)
            {
                root1 = (-b + sqrt(dTerm))/(2*a);
                root2 = (-b - sqrt(dTerm))/(2*a);
                printf("\nThe given equation has distinct real roots");
                printf("\nThe roots of the equations are %f and %f\n", root1, root2);
            }
            /// if dTerm is negative, complex root
            else
            {
                float realTerm = -b / (2.0*a);
                float imagTerm = sqrt(abs((int)dTerm)) / (2*a);
                printf("\nThe given equation has complex conjugate root");
                printf("\nThe roots are: %f +- %fi", realTerm, imagTerm);

            }
            break;
        case '3':
            printf("Enter the angle: ");
            scanf("%f", &angle);
            printf("\nEnter the choice: \n");
            printf("1. Sine\n");
            scanf("\n%c", &achoice);
            switch(achoice)
            {
                case '1':
                    result = sine(angle);
                    printf("\nThe sine of %f is %f", angle, result);
                    break;
            }
            break;
        case '4':
            // IMPLEMENT IT
            printf("Solve simultaneous equations");
            break;
        case '5':
            // IMPLEMENT IT
            printf("Complex number operations");
            break;
        case '6':
            exit(0);
            break;
        default:
            printf("You entered invalid choice, enter only 1 to 6");
            break;
        }
    }
    return 0;
}
