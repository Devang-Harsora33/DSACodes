#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

float stack[50];
char postfix[50];
int top = -1;

void push(int a)
{
    top++;
    stack[top] = a;
}

int pop()
{
    int a = stack[top--];
    return a;
}

void evaluate(){
    char x, y;
    float op2, op1, result;
    int i = 0;
    while(postfix[i] != '\0'){
        x = postfix[i];
        if(isalpha(x) || isdigit(x)){
            y = (float)x - '0';
            push(y);
        }

        else if(x == '+' || x == '-' || x == '*' || x == '/' || x == '%'){
            op2 = pop();
            op1 = pop();
            if(x == '+')
            result = op1 + op2;

            else if(x == '-')
            result = op1 - op2;

            else if(x == '*')
            result = op1 * op2;

            else if(x == '/')
            result = op1 / op2;

            else if(x == '%')
            result = (int)op1 % (int)op2;

            push(result);
            
        }
        i++;
    }
     printf("\nResult: %.2f",stack[top]);
}

int main(){
    printf("Enter the postfix expression: \n");
    scanf("%s",postfix);
    evaluate();
    return 0;
}