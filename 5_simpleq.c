/*Write a program to implement SIMPLE 
QUEUE using arrays that performs following operations: 
a. INSERT 
b. DELETE 
c. DISPLAY*/
#include<stdio.h>
#define n 3

int queue[n];
int rear=-1;
int front=-1;
void insert();
void delete();
void display();

int main()
{
    int ch,i=0;
    printf("\n1)Insert Element in queue");
    printf("\n2)Delete Element in queue");
    printf("\n3)Display Element of queue");
    printf("\n4)Exit");
    while(i>=0)
    {
        printf("\nEnter your choice:");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("\nInvalid Input!!");    
        }
    }
}
void insert()
{
    int item;
    if(rear==n-1)
    {
        printf("Queue Overflow!!");
    }
    else
    {
        if(front==-1)
        {
            front=0;
        }
        printf("Insert element in queue:");
        scanf("%d",&item);
        rear++;
        queue[rear]=item;
    }
}
void delete()
{
    if(front==-1)
    {
        printf("Queue underflow!!");
    }
    else
    {
        printf("Element deleted from queue is :%d",queue[front]);
        if (front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front++;
        }
    }
}
void display()
{
    int i;
    if (front==-1)
    {
        printf("Queue is Empty");
    }
    else
    {
        printf("Queue is:");
        for ( i = front; i <= rear; i++)
        {
            printf("%d ",queue[i]);
        }   
    }
}