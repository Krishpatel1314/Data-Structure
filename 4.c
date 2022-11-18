//Implement a program to convert infix notation to postfix notation
//using stack
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
char stack[100];
int i,j,k,top = -1;

void push(char a)
{
    top++;
    stack[top]=a;
}
char pop()
{
    if(top==-1) 
        return -1;
    else 
        return stack[top--];
}

int getpriority(char a)
{
    if(a == '+' || a == '-')
        return 1;
    if(a == '*' || a == '/'||a=='%')
        return 2;
    if(a == '^')
        return 3;
    return 0;
}
int main()
{
    char exp[100],*e,x;
    printf("Enter the expression: ");
    scanf("%s",exp);
    e=exp;
    while(*e!='\0')
    {
        if(isalnum(*e))
        {    
            printf("%c",*e);   
        }
        else
        {
            while(getpriority(stack[top])>=getpriority(*e))
            printf("%c",pop());
            push(*e);
        }
        e++;
    }
    while(top!=-1)
    {
        printf("%c",pop());
    }
    return 0;
}