/*Write a program to implement following operations on the circular
linked list.
a. Insert a node at the end of the linked list.
b. Insert a node before specified position.
c. Delete a first node of the linked list.
d. Delete a node after specified position.
e. Insert a node at the front of the linked list.[extra]
f. Delete a last node of the linked list.[extra]*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *start=NULL;
void i_atend();
void i_beforenode();
void d_atfirst();
void d_afternode();
void createlist();
void display();

int main()
{
    int ch,i=0;
    createlist();
    printf("\n1)Insert a node at the end of the linked list..");
    printf("\n2)Insert a node before specified position.");
    printf("\n3)Delete a first node of the linked list.");
    printf("\n4)Delete a node after specified position.");
    printf("\n5)Display the List.");
    printf("\n6)Exit");
    while(i>=0)
    {
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                i_atend();
                break;
            case 2:
                i_beforenode();
                break;
            case 3:
                d_atfirst();
                break;
            case 4:
                d_afternode();
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
        new=(struct node*)malloc(sizeof(struct node));
        new->data=item;
        if (start==NULL)
        {
            new->next=new;
            start=new;
        }
        else
        {
            ptr=start;
            while (ptr->next!=start)
                ptr=ptr->next;
            ptr->next=new;
            new->next=start;
        }
        scanf("%d",&item);
    }
}
void display()
{
    struct node *ptr;
    ptr=start;
    while (ptr->next!=start)
    {
        printf("%d  ",ptr->data);
        ptr=ptr->next;
    }
    printf("%d",ptr->data);
}
void i_atend()
{
    struct node *new,*temp;
    int item;
    printf("Enter the data you want to enter:");
    scanf("%d",&item);
    new=(struct node*)malloc(sizeof(struct node));
    new->data=item;
    if (start==NULL)
    {
        start=new;
        new->next=start;
    }
    else
    {
        temp=start;
        while (temp->next!=start)
        {
            temp=temp->next;
        }
        temp->next=new;
        new->next=start;
    }  
}
void i_beforenode()
{
    struct node *new,*temp,*pre;
    int item,val;
    printf("Enter the number you want to insert:");
    scanf("%d",&item);
    printf("Enter the value after which you want to insert:");
    scanf("%d",&val);
    new=(struct node *)malloc(sizeof(struct node));
    new->data=item;
    temp=start;
    while (temp->data!=val)
    {
        pre=temp;
        temp=temp->next;
    }
    pre->next=new;
    new->next=temp;
    printf("%d Inserted before %d",item,val);
}
void d_atfirst()
{
    struct node *temp;
    if (start==NULL)
        printf("List is Empty!!");
    else
    {
        temp=start;
        while (temp->next!=start)
            temp=temp->next;   
        temp->next=start->next;
        free(start);
        start=temp->next;
        printf("Element deleted from front");
    }  
}
void d_afternode()
{
    struct node *temp,*ptr;
    int item;
    printf("Enter the value after which the node has to be deleted:");
    scanf("%d",&item);
    temp=start;
    ptr=temp;
    while (ptr->data!=item)
    {
        ptr=temp;
        temp=temp->next;
    }
    ptr->next=temp->next;
    if (temp==start)
    {
        start=ptr->next;
    }
    free(temp);
    printf("Elemet deleted after %d",item);
}