//Introduction to pointers. Call by Value and Call by reference
#include<conio.h>
#include<stdio.h>
void swap();
void swapp();
int main()
{
    int a,b;
    printf("Enter fisrt number:");
    scanf("%d",&a);
    printf("Enter second number:");
    scanf("%d",&b);
    swap(a,b);
    swapp(&a,&b);
    printf("\nAfter swapping with call by reference values are:");
    printf("%d  ,%d  ",a,b);
    getch();
}
void swap(int j,int k)
{
    int l;
    l=j;
    j=k;
    k=l;
    printf("After swapping with call by value are:");
    printf("%d  ,%d  ",j,k);
}
void swapp(int *j,int *k)
{
    int l;
    l=*j;
    *j=*k;
    *k=l;
}