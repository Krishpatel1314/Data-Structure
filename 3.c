// Implement a program for stack that performs following operations
// using array.
// a. PUSH
// b. POP
// c. PEEP
// d. CHANGE
// e. DISPLAY

#include<stdio.h>
#include<conio.h>
#define n 5
int top=-1,stack[n];
void push();
void pop();
void display();
void peep();
void change();
int main()
{
    int i,ch;
    printf("1)Push\n2)Pop\n3)Peep\n4)Change\n5)Display\n6)Exit");
    do
    {
       printf("\nEnter the choice:");
       scanf("%d",&ch);
       switch(ch)
       {
           case 1: push();
           break;
           case 2: pop();
           break;
           case 3: peep();
           break;
           case 4: change();
           break;
           case 5: display();
           break;
           default:
           printf("Invalid Input");
       }
    }while(ch!=6);
    getch();
}

void push()
{
    int a;
    if(top>n-1)
    printf("Stack Overflow. Push Not Possible!!");
    else
    {
        printf("Enter element to push:");
        scanf("%d",&a);
        top++;
        stack[top]=a;
    }
}
void pop()
{ 
    int a; 
    if(top==-1) 
    { 
        printf("Stack Underflow. Pop not possible."); 
    } 
    else 
    {
        printf("Deleted element is %d",stack[top]);
        top--;
    }
}
void peep()
{
    int a;
    if(top==-1)
    {
        printf("Stack is empty!!");
    }
    else
    {
        a=stack[top];
        printf("Element at peek:%d",a);
    }
}
void change()
{
    int p,v;
    printf("Enter the position of new element:");
    scanf("%d",&p);
    printf("Enter the value of new element:");
    scanf("%d",&v);
    if((top-p+1)<=-1)
    {
        printf("Change not possible!!");
    }
    else
    {
        stack[top-p+1]=v;
        printf("New element is successfully added!!");
    }
}
void display()
{
    int i;
    if(top==-1)
    {
        printf("Stack is empty!!");
    }
    else
    {
        printf("Stack is...\n");
        for(i=top;i>=0;--i)
        printf("%d  ",stack[i]);
    }
}