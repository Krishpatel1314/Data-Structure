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
void i_insort();
void d_atfirst();
void d_beforepos();
void d_afterpos();
void display();

int main()
{
    int ch,i=0;
    printf("\n1)Insert a node at the front of the linked list.");
    printf("\n2)Insert a node at the end of the linked list.");
    printf("\n3)Insert a node such that linked list is in ascending order.");
    printf("\n4)Delete a first node of the linked list.");
    printf("\n5)Delete a node before specified position.");
    printf("\n6)Delete a node after specified position.");
    printf("\n7)Display the List.");
    printf("\n8)Exit");
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
            // case 3:
            //     i_insort();
            //     break;
            case 4:
                d_atfirst();
                break;
            // // case 5:
            // //     d_beforepos();
            // //     break;
            // case 6:
            //     d_afterpos();
            //     break;
            case 7:
                display();
                break;
            case 8:
                return 0;
            default:
                printf("\nInvalid Input!!");    
        }
    }
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
}
// void i_atfront()
// {
//     int item,pos;
//     struct node *temp,*newnode;
//     newnode=malloc(sizeof(struct node));
//     printf("Enter position to be inserted:");
//     scanf("%d",&pos);
//     printf("Enter number to be inserted:");
//     scanf("%d",&item);
//     temp=start;
//     newnode->data=item;
//     newnode->next=0;
//     while (i<pos-1)
//     {
//         temp=temp->next;
//         i++;
//     }
//     newnode->next=temp->next;
//     temp->next=newnode;
// }
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
    }
}
// void d_beforepos()
// {
//     struct node *temp,*prenode;
//     if (start==NULL)
//     printf("List is Empty!!");
//     else
//     {
//         temp=start;
//         while (temp->next!=0)
//         {
//             pernode=temp;
//             temp=temp->next;
//         }
//         free(temp);
//         prenode->next=0;
//     }
// }
void d_afterpos()
{
    struct node *temp,*nextnode;
    int i, pos;
    printf("Enter position to be inserted:");
    scanf("%d",&pos);
    temp=start;
    for ( i = 0; i < pos; i++)
    {
        nextnode=temp;
        temp=temp->next;
        if (temp==NULL)
        {
            printf("Deletion is not possible!!");
        }
    }
    nextnode->next=temp->next;
    free(temp);
    printf("Deleted node %d",pos+1);
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
