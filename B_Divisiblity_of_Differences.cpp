#include <bits/stdc++.h>
using namespace std;
#define n 1000005
bool a[n];
long long int k=1;
long long int twin[n];
void sieve()
{
    long long int i,j;
    a[0]=a[1]=1;
    for(i=4;i<=n;i=i+2)
    {
        a[i]=1;
    }
    for(i=3;i<=sqrt(n);i=i+2)
    {
        for(j=i*i;j<=n;j=j+2*i)
        {
            a[j]=1;        //3*3, 3*5,3*7.....
        }
    }
    for(i=2;i<=n;i++)
    {
        if(a[i]==0)
        {
           twin[k]=i;
           k++;
        }
    }



}

int main()
{
    long long int r,b,x,l,g,m,t=0,p,q;
    long double c;
    //freopen("11728in.txt","r",stdin);
    //freopen("11728out.txt","w",stdout);
    sieve();
    while(cin>>m)
    {
        t++;
        b=0;
        if(m==0)
        {
            break;
        }
        //in>>m;

      for(q=1;q<=m;q++)
      {

        l=q;
        r=1;
        for(g=1;g<=k && twin[g]<=sqrt(l);g++)
        {
          c=0;
          p=twin[g];
          if(l%twin[g]==0)
          {

            while(l%twin[g]==0)
            {
                c++;
                l=l/twin[g];
                if(l==0 || l==1)
                {
                    break;
                }

             }
             //cout<<q<<" "<<c<<endl;

              r=r*(pow((double)p,c+1.0)-1)/(p-1);

           }



        }
        if(l!=1)
        {
            r=r*(pow((double)l,2)-1)/(l-1);
        }
        //cout<<q<<" "<<r<<endl;




          if(m==r)
          {
            b=1;
            x=q;
          }
        }
        if(b==1)
        {
           printf("Case %lld: %lld\n",t,x);
        }
        else if(b==0)
        {
            printf("Case %lld: -1\n",t);
        }
     }

        return 0;

}