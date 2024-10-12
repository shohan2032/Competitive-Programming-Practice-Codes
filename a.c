#include<stdio.h>
#include<string.h>

void strcp(char a[])
{
    char result[10];

    //copying a string to result string
    strcpy(result,a);
    printf("%s\n",result);
}
void strcm(char a[],char b[])
{
    if(strcmp(a,b) == 0)
        printf("Both string are same\n");
    else if(strcmp(a,b) > 0)
        printf("First string is greater than second string\n");
    else
        printf("Second string is greater than first string\n");
}

void strca(char a[],char b[])
{
    char c[1000];
    strcpy(c,a);
    printf("Concatanation of %s and %s:%s\n",c,b,strcat(a,b));
}

void strle(char a[])
{
    printf("The length of this string is:%d\n",strlen(a));
}

int main()
{
    char a[20],b[20];

    //getting input
    scanf("%s",a); 
    scanf("%s",b);

    //displaying string
    printf("Displaying string:\n");
    printf("%s\n",a);
    printf("%s\n",b);

    printf("Output from strcp function:\n");
    strcp(a);
    printf("Output from strcm function:\n");
    strcm(a,b);
    printf("Output from strle function:\n");
    strle(a);
    printf("Output from strca function:\n");
    strca(a,b);
    
}