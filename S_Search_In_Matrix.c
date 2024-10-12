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
    int x;
    scanf("%d",&x);
    for(int i = 0;i < r;i++)
    {
        for(int j = 0;j < c;j++)
        {
            if(x == arr[i][j])
            {
                printf("will not take number\n");
                return 0;
            }
        }
    }
    printf("will take number\n");
}
/*Problem_link

*/