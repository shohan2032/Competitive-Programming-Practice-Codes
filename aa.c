#include <stdio.h>
#include <string.h>
int main()
{
    char ch[10005];
    scanf("%s",ch);
    char a[10005],b[10005];
    int len  = strlen(ch);
    // printf("%d",len);
    if(len & 1)
        printf("-1\n");
    else
    {
        for(int i = 0;i < len/2;i++)
            a[i] = ch[i];
        for(int i = len/2;i < len;i++)
            b[i] = ch[i];
        printf("%s",b);
    }
    return 0;
}
/*Problem_link

*/