#include<conio.h>
#include<stdio.h>
int main()
{
    int a,b;
    printf("Enter fisrt number:");
    scanf("%d",&a);
    printf("Enter second number:");
    scanf("%d",&b);
    swap(a,b);
    printf("After swapping values are:");
    printf("%d  ,%d  ",a,b);
    swapp(&a,&b);
    printf("\nAfter swapping values are:");
    printf("%d  ,%d  ",a,b);
    getch();
}
void swap(int j,int k)
{
    int l;
    l=j;
    j=k;
    k=l;
}
void swapp(int *j,int *k)
{
    int l;
    l=*j;
    *j=*k;
    *k=l;
}