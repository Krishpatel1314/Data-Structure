#include<stdio.h>
#include<conio.h>
#define n 50
char stack[n];
int top=-1,j=0;
char postfix[50];
void push(char);
char pop();
int priority(char);
int main()
{
    int i;
    char element,ch;
    char infix[50];
    printf("Enter infix expression\n");
    gets(infix);
    printf("\nSymbol\tStack content\tpostfix expression");
    for(i=0;infix[i]!=NULL;i++)
    {
        ch=infix[i];
        if(ch>='a' && ch<='z')
        {
            postfix[j]=ch;
            j++;
        }
        else if(ch=='(')
        {
            push(ch);
        }
        else if(ch==')')
        {
            while((element=pop())!='(')
            {
                postfix[j]=element;
                j++;
            }
        }
        else
        {
            while(priority(ch)<=priority(stack[top]))
            {
                if(stack[top]=='(')
                break;
                element=pop();
                postfix[j]=element;
                j++;
            }
            push(ch);
        }
    postfix[j]=NULL;
    printf("\n%c\t%s\t\t%s",ch,stack,postfix);
    }
    return 0;
}
void push(char ch)
{
    if(top>=n-1)
    {
        printf("overflow");
    }
    else
    {
        top=top+1;
        stack[top]=ch;
    }
}
char pop()
{
    if(top==-1) 
        printf("Stack underflow");
    else 
        return stack[top--];
}
int priority(char ch)
{
    char operand[6]={'+','-','*','/','(','\0'};
    int prio[5]={1,1,2,2,3};
    int i,a;
    for(i=0;i<5;i++)
    {
        if(ch==operand[i])
        {
            a=prio[i];
            break;
        }
    }
    return a;
}