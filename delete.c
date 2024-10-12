#include <stdio.h>
#define ll long long

int main()
{
    int r,c;
    scanf("%d%d",&r,&c);
    int arr[r+5][c+5];
    for(int i = 0;i < r;i++)
    {
        for(int j = 0;j < c;j++)
            scanf("%d",&arr[i][j]);
    }
    for(int i = 0;i < r;i++)
    {
        for(int j = 0;j < c;j++)
            printf("%d ",arr[i][j]);
        printf("\n");
    }
    return 0;
}
/*Problem_link

*/