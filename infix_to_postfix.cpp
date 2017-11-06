
/****************************************************************
Program: Conversion of Infix to Postfix String and Evaluation
Language: C/C++
by Bibek Subedi
June 13, 2011
Operators Used
1. '+' For addition
2. '-' For Subtraction
3. '*' For Multiplication
4. '/' For Division
5. '^' For Exponentiation
Program Limitations
* This program Only process single digit operations
* Can't handle unary operation
* Only process left to right associativity
***************************************************/
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#define MAX_SIZE 20
using namespace std;
template <class T>
class Stack {
private:
    T item[MAX_SIZE];
    int top;

public:
    Stack()
    {
        top = -1;
    }
    void push(T data)
    {
        if (!this->is_full())
            item[++top] = data;
        else {
            cout << "Stack Error" << endl;
            exit(10);
        }
    }
    T pop()
    {
        if (!this->is_empty())
            return item[top--];
        else {
            cout << "Stack is Empty" << endl;
            exit(11);
        }
    }
    int size()
    {
        return top + 1;
    }
    bool is_empty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
    bool is_full()
    {
        if (top == MAX_SIZE - 1)
            return true;
        else
            return false;
    }
    void display()
    {
        for (int i = 0; i < this->size(); i++) {
            cout << item[i] << " ";
        }
        cout << endl;
    }
    T return_top()
    {
        return item[top];
    }
};
class Convert {
private:
    bool num_flag;
    bool two_digit_flag;

public:
    Convert();
    string return_with_bracket(string infix);
    void to_Postfix(string infix, char postfix[]);
    bool prcd(char op1, char op2);
    int isOperand(char op);
    int isOperator(char op);
    bool return_flag()
    {
        return num_flag;
    }
};
Convert::Convert()
{
    this->num_flag = false;
    this->two_digit_flag = false;
}
string Convert::return_with_bracket(string infix)
{
    return ("(" + infix + ")");
}
bool Convert::prcd(char op1, char op2)
{
    if ((op1 == '+' || op1 == '-' || op1 == '*' || op1 == '/') && op2 == '(')
        return true;
    if (op1 == '+' && op2 == '+')
        return true;
    if (op1 == '-' && op2 == '-')
        return false;
    if (op1 == '-' && op2 == '+')
        return false;
    if (op1 == '+' && op2 == '-')
        return false;
    if (op1 == '/' && op2 == '/')
        return false;
    if (op1 == '/' && (op2 == '-' || op2 == '+'))
        return true;
    if (op1 == '*' && (op2 == '+' || op2 == '-'))
        return true;
    if ((op1 == '-' || op1 == '+') && (op2 == '*' || op2 == '/'))
        return false;
    if ((op1 == '$' || op1 == '+') && (op2 == '*' || op2 == '/' || op2 == '-'))
        return true;
    if ((op1 == '-' || op1 == '+' || op1 == '*' || op1 == '/') && op2 == '^')
        return false;
    if (op1 == '^' && (op2 == '+' || op2 == '*' || op2 == '/' || op2 == '-'))
        return false;
}
int Convert::isOperand(char op)
{
    return (op >= '0' && op <= '9');
}
int Convert::isOperator(char op)
{
    return (op == '+' || op == '-' || op == '/' || op == '*' || op == '^');
}
void Convert::to_Postfix(string infix, char postfix[])
{
    int position, outpos = 0;
    char c;
    int count = 0;
    char temp;
    char stacktop;
    Stack<char> stack;
    for (position = 0; (c = infix[position]) != '\0'; position++) {
        if (this->isOperand(c)) {
            postfix[outpos++] = c;
            this->num_flag = true;
            count++;
            if (count >= 2) {
                this->two_digit_flag = true;
            }
        }
        else if (this->isOperator(c)) {
            count = 0;
            if (isOperator(infix[position]) && isOperator(infix[position + 1])) {
                cout << "\aMissing argument in between " << infix[position] << " and " << infix[position + 1]
                     << " in column " << position + 1 << endl;
                exit(9);
            }
            if (this->prcd(c, stacktop)) {
                stacktop = stack.return_top();
                stack.push(c);
                stacktop = c;
            }
            else {
                while (true) {
                    temp = stack.pop();
                    postfix[outpos++] = temp;
                    stacktop = stack.return_top();
                    if (prcd(c, stacktop) || stacktop == '(')
                        break;
                }
                stack.push(c);
                stacktop = stack.return_top();
            }
        }
        else if (c == '(') {
            count = 0;
            stack.push(c);
            stacktop = stack.return_top();
        }
        else if (c == ')') {
            count = 0;
            while (1) {
                if (stack.size() == 0) {
                    cout << "Warning!! Number of ')' is greater than '('" << endl;
                    exit(2);
                }
                temp = stack.pop();
                if (temp != '(') {
                    postfix[outpos++] = temp;
                }
                else {
                    break;
                }
            }
            stacktop = stack.return_top();
        }
        else {
            cout << "Invalid input";
            exit(3);
        }
        if (infix[position] == ')' && infix[position + 1] == '(') {
            stack.push('*');
            stacktop = stack.return_top();
        }
    }
    if (stack.size() != 0) {
        cout << "Warning!!Number of '(' is greater than ')'" << endl;
        // exit(6);
    }
    if (!this->return_flag()) {
        cout << "You must Enter Numeric value for calculation" << endl;
        cout << "This program cannot perform operations on variables";
        exit(5);
    }
    if (this->two_digit_flag) {
        cout << "Sory! Althoug u may  have entered right string" << endl;
        cout << "this program is only for single digit operation" << endl;
        exit(8);
    }
    postfix[outpos] = '\0';
}
class Evaluate {
public:
    double eval(char expr[], Convert&);
    double oper(int symb, double op1, double op2);
};
double Evaluate::oper(int symb, double op1, double op2)
{
    switch (symb) {
    case '+':
        return (op1 + op2);
    case '-':
        return (op1 - op2);
    case '*':
        return (op1 * op2);
    case '/':
        return (op1 / op2);
    case '^':
        return (pow(op1, op2));
    }
}
double Evaluate::eval(char expr[], Convert& convert)
{
    int c, position;
    char temp1;
    int count = 0;
    double opnd1, opnd2, value;
    Stack<double> stack;
    for (position = 0; (c = expr[position]) != '\0'; position++) {
        if (convert.isOperand(c)) {
            temp1 = double(c - '0');
            stack.push(temp1);
        }
        else {
            opnd2 = stack.pop();
            if (stack.size() == 0) {
                cout << "This program cannot process unary operation";
                exit(1);
            }
            opnd1 = stack.pop();
            value = oper(c, opnd1, opnd2);
            stack.push(value);
        }
    }
    if (stack.size() >= 2) {
        cout << "Sory! this program cannot calculate this" << endl;
        cout << "Enter +, *, /, - or ^ between bracket" << endl;
        exit(4);
    }
    return (stack.pop());
}
int main()
{
    Convert convert;
    Evaluate evaluate;
    string bracketted_infix;
    char infix[50], postfix[50];
    char choice;
    while (1) {
        cout << "Enter string: ";
        cin >> infix;
        cout << endl;
        cout << "Entered String: " << infix << endl;
        bracketted_infix = convert.return_with_bracket(infix);
        convert.to_Postfix(bracketted_infix, postfix);
        cout << "Equivalent Postfix string: " << postfix << endl;
        cout << "RESULT: ";
        cout << evaluate.eval(postfix, convert);
        cout << "\nCalculate another string?(y/n) ";
        cin >> choice;
        cout << endl;
        if (choice == 'n')
            break;
    }
    return 0;
}