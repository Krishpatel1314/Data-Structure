#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *start=NULL;
void createlist();
void i_atfront();
void i_atend();
void i_afternode();
void i_beforenode();
void d_atfirst();
void d_atlast();
void d_afternode();
void display();

int main()
{
    int ch,i=0;
    createlist();
    printf("\n1)Insert a node at the front of the linked list.");
    printf("\n2)Insert a node at the end of the linked list.");
    printf("\n3)Insert a node after a given node.");
    printf("\n4)Insert a node before a given node.");
    printf("\n5)Delete a first node of the linked list.");
    printf("\n6)Delete a last node of the linked list.");
    printf("\n7)Delete a node after specified node.");
    printf("\n8)Display the List.");
    printf("\n9)Exit");
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
                i_afternode();
                break;
            case 4:
                i_beforenode();
                break;
            case 5:
                d_atfirst();
                break;
            case 6:
                d_atlast();
                break;
            case 7:
                d_afternode();
                break;
            case 8:
                display();
                break;
            case 9:
                return 0;
            default:
                printf("\nInvalid Input!!");    
        }
    }
}
void createlist()
{
    struct node *new,*temp;
    int item,i,n;
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    start=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data of node : ");
    scanf("%d", &item);
    start->data = item; 
    start->next = NULL; 
    temp = start;
    for(i=2; i<=n; i++)
    {
        new=(struct node *)malloc(sizeof(struct node));
        scanf("%d", &item);
        new->data = item; 
        new->next = NULL; 
        temp->next = new; 
        temp=temp->next;
    }
    printf("\tList Created!!");
}
void i_atfront()
{
    int item;
    struct node *temp;
    temp=malloc(sizeof(struct node));
    printf("Enter number to be inserted:");
    scanf("%d",&item);
    temp->data=item;
    temp->next=start;
    start=temp;
    printf("%d inserted at front",item);
}
void i_atend()
{
    int item;
    struct node *temp,*head;
    temp=malloc(sizeof(struct node));
    printf("Enter number to be inserted:");
    scanf("%d",&item);
    temp->next=0;
    temp->data=item;
    head=start;
    while(head->next!=NULL)
    {
        head=head->next;
    }
    head->next=temp;
    printf("%d inserted at End",item);
}
void i_afternode()
{
    struct node *new,*temp;
    int item,val;
    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data of node : ");
    scanf("%d", &item);
    new->data = item; 
    new->next = NULL;
    printf("Enter the value after which you want to insert:");
    scanf("%d",&val);
    temp=start;
    while (temp!=NULL && temp->data!=val)
    {
        temp=temp->next;
    }
    new->next=temp->next;
    temp->next=new;    
    printf("%d Inserted after %d",item,val);
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
        start=start->next;
        free(temp);
        printf("Element deleted from front");
    }
    
}
void d_atlast()
{
    struct node *temp,*pre;
    temp=start;
    while (temp->next!=NULL)
    {
        pre=temp;
        temp=temp->next;
    }
    pre->next=NULL;
    free(temp);
    printf("Element deleted from end");
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
    free(temp);
    printf("Elemet deleted after %d",item);
}
void display()
{
    struct node *temp;
    temp=start;
    if (temp==NULL)
    {
        printf("Empty List");
    }
    else
    {
        temp=start;
        printf("List:");
        while (temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }    
}
