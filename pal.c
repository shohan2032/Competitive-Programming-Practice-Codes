#include <stdio.h>

void print_2d_array(int (*arr) [100],int r,int c)
{
    for(int i = 0;i < r;i++)
    {
        for(int j = 0;j < c;j++)
            printf("%d ",arr[i][j]);
        printf("\n");
    }
}

int main()
{
  int r,c;
  int arr[100][100];
  scanf("%d%d",&r,&c);
  for(int i = 0;i < r;i++)
  {
    for(int j = 0;j < c;j++)
        scanf("%d",&arr[i][j]);
  }
  print_2d_array(arr,r,c);
  return 0;
}