//Implement a program to insert, delete and search an element from
//array.
#include<conio.h>
#include<stdio.h>
int main()
{
    int i,a[20],n,ch,m,s,f=0,p,e;
    printf("1)Create an array \n2)Insert an elemnt\n3)Delete an element\n4)Search an element\n5)Display\n6)Exit");
    while(ch!=7)
    {
        printf("\nEnter the choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter no of element you want to enter:");
            scanf("%d",&n);
            for ( i = 0; i < n; i++)
            {
                scanf("%d",&a[i]);
            }
            break;
            case 2:
            printf("Enter the the position where you want to add the element:");
            scanf("%d",&p);
            printf("Enter the elemnt you want to add:");
            scanf("%d",&e);
            for(i=n-1;i>=p-1;i--)
                a[i+1]=a[i];
            a[p-1]=e;
            n++;
            break;
            case 3:
            printf("Enter index you want to delete:");
            scanf("%d",&m);
            for ( i = m; i < n; i++)
            {
                a[i]=a[i+1];
                n--;
            }
            n++;
            break;
            case 4:
            printf("Enter element you want search:");
            scanf("%d",&s);
            for ( i = 0; i < n; i++)
            {
                if(s==a[i])
                {
                    printf("Element found ");
                    f=1;
                }
            }
            if(f==0)
            {
                printf("Element not found!");
            }
            break;
            case 5:
            for ( i = 0; i < n; i++)
            {
                printf("%d ",a[i]);
            }
            break;
            case 6:
            break;
            default:
            printf("Invalid Input!!");
        }
    }
    getch();
}