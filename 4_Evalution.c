//Evalution of Postfix expression
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

char stack[100];
int top = -1;

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
void display()
{
    int i;
    printf("\nStack is :");
    for(i=0;i<=top;i++)
        printf("%d |",stack[i]);
}
int main()
{
    char postfix[50],a;
    float op1,op2,result;
    int i=0;
    printf("Enter Postfix Expression:");
    scanf("%s",postfix);
    while(i<=strlen(postfix)-1)
    {
        a=postfix[i];
        if(isdigit(a))
        {
            push(a-'0');
        }
        else
        {
            op1=pop();
            op2=pop();
            switch (a)
            {
                case '^':
                    result=pow(op2,op1);
                    break;
                case '/':
                    result=op2/op1;
                    break;
                case '+':
                    result=op2+op1;
                    break;
                case '-':
                    result=op2-op1;
                    break;
            }
            push(result);
        }
        display();
        i++;
    }
    printf("\nResult:%d",pop());
    return 0;
}