#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int line = (n+1)/2 + 5;
    int sp = line-1;
    for(int i= 1;i <= line;i++)
    {
        for(int j = 1;j <= sp;j++)
            printf(" ");
        for(int j = 1;j <= i*2 - 1;j++)
            printf("*");
        printf("\n");
        sp--;
    }
    for(int i = 1;i <= 5;i++)
    {
        for(int j = 1;j <= 5;j++)
            printf(" ");
        for(int j= 1;j <= n;j++)
            printf("*");
        printf("\n");
    }
}