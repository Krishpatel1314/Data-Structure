/*Write a program to implement following operations on the doubly
linked list.
a. Insert a node at the front of the linked list.
b. Insert a node at the end of the linked list.
c. Delete a last node of the linked list.
d. Delete a node before specified position.*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *start=NULL;
void createlist();
void i_atfront();
void i_atend();
void d_atlast();
void d_beforenode();
void display();
int main()
{
    int ch,i=0;
    createlist();
    printf("\n1)Insert a node at the front of the linked list.");
    printf("\n2)Insert a node at the end of the linked list.");
    printf("\n3)Delete a last node of the linked list.");
    printf("\n4)Delete a node before specified node.");
    printf("\n5)Display the List.");
    printf("\n6)Exit");
    while(i>=0)
    {
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                i_atfront();
                break;
            case 2:
                i_atend();
                break;
            case 3:
                d_atlast();
                break;
            case 4:
                d_beforenode();
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
}
void createlist()
{
    struct node *new,*ptr;
    int item;
    printf("Enter -1 to end");
    printf("\nEnter the data:");
    scanf("%d",&item);
    while (item!=-1)
    {
        if (start==NULL)
        {
            new=(struct node*)malloc(sizeof(struct node));
            new->prev=NULL;
            new->data=item;
            new->next=NULL;
            start=new;
        }
        else
        {
            ptr=start;
            new=(struct node*)malloc(sizeof(struct node));
            new->data=item;
            while (ptr->next!=NULL)
                ptr=ptr->next;
            ptr->next=new;
            new->prev=ptr;
            new->next=NULL;
        }
        scanf("%d",&item);
    }
}
void display()
{
    struct node *ptr;
    ptr=start;
    while (ptr!=NULL)
    {
        printf("%d  ",ptr->data);
        ptr=ptr->next;
    }
}
void i_atfront()
{
    int item;
    struct node *temp;
    printf("Enter number to be inserted:");
    scanf("%d",&item);
    temp=malloc(sizeof(struct node));
    temp->data=item;
    start->prev=temp;
    temp->next=start;
    temp->prev=NULL;
    start=temp;
    printf("%d inserted at front",item);
}
void i_atend()
{
    struct node *new,*temp;
    int item;
    printf("Enter the data you want to enter:");
    scanf("%d",&item);
    new=(struct node*)malloc(sizeof(struct node));
    new->data=item;
    temp=start;
    while (temp->next!=NULL)
        temp=temp->next;
    temp->next=new;
    new->prev=temp;
    new->next=NULL;
}
void d_atlast()
{
    struct node *temp;
    temp=start;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
    printf("Element deleted from end");
}
void d_beforenode()
{
    struct node *temp,*ptr;
    int item;
    printf("Enter the value before which the node has to be deleted:");
    scanf("%d",&item);
    temp=start;
    while (temp->data!=item)
    {    
        temp=temp->next;
    }
    ptr=temp->prev;
    ptr->prev->next=temp;
    temp->prev=ptr->prev;
    free(ptr);
    printf("Elemet deleted before %d",item);
}