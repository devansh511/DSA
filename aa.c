#include<stdio.h>
void main()
{
    int b,i,n,j;
    for(i=1;i<=4;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%d",j);
        }
        printf("\n");
    }
    b=3;
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=b;j++)
        {
            printf("%d",j);
        }
        b--;
        printf("\n");
    }
}