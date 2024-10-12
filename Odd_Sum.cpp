#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n;
        scanf("%lld",&n);
        if(n <= 2ll)
            printf("1\n");
        else{
            n -= 2;
            printf("%lld\n",1+(n*(n+1)));
        }
    }
    return 0;
}