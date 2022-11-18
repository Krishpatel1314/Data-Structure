//PROGRAM OF DOUBLE ENDED QUEUE
#include<conio.h>
#include<stdio.h>
#define n 5
int dqueue[n],rear=-1,front=0,te=0;
void addrear();
void deleterear();
void addfront();
void deletefront();
void display();

int main()
{
    int ch,i=0,j;
    printf("\n1)Insert rear in queue");
    printf("\n2)Delete rear in queue");
    printf("\n3)Insert front in queue");
    printf("\n4)Delete front in queue");
    printf("\n5)Display Element of queue");
    printf("\n6)Exit");
    while(i>=0)
    {
        printf("\nEnter your choice:");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                addrear();
                break;
            case 2:
                deleterear();
                break;
            case 3:
                addfront();
                break;
            case 4:
                deletefront();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("\nInvalid Input!!");    
        }
    }
    return 0;
}
void addrear()
{
    int item;
    if (te==n)
    {
        printf("Queue is full!!");
    }
    else
    {
        printf("Enter a number:");
        scanf("%d",&item);
        rear=(rear+1)%n;
        dqueue[rear]=item;
        te++;
    }
}
void deleterear()
{
    if (te==0)
    {
        printf("Queue is Empty!!");
    }
    else
    {
        if (rear==-1)
        {
            rear=n-1;
        }
        printf("Number deleted from rear end:%d",dqueue[rear]);
        rear--;
        te--;
    }
}
void addfront()
{
    int item;
    if (te==n)
    {
        printf("Queue is full!!");
    }
    else
    {
        printf("Enter a number:");
        scanf("%d",&item);
        if (front==0)
        {
            front=n-1;
        }
        else
        {
            front--;
        }
        dqueue[front]=item;
        te++;
    }
}
void deletefront()
{
    if (te==0)
    {
        printf("Queue is Empty!!");
    }
    else
    {
        printf("Number deleted from rear end:%d",dqueue[front]);
        front=(front+1)%n;
        te--;
    }
}
void display()
{
    int i,a=front;
    if (te==0)
    {
        printf("Queue is Empty!!");
    }
    else
    {
        printf("Queue is:");
        for ( i = 1; i <= te; i++)
        {
            printf("%d ",dqueue[a]);
            a=(a+1)%n;
        }   
    }
}