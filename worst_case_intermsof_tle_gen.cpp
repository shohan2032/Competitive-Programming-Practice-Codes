#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int t = rnd.next(1,100);
    cout << t <<endl;
    while(t--)
    {
        int n = rnd.next(1,1000);
        int a = (n-1)*(n-1);
        // while(1){
            int d = rnd.next(1,a+a);
            cout << n << " "<< d << endl;
            // int f = 0;
            // for(int i = 1;i <= n;i++)
            // {
            //     for(int j = 1;j <= n;j++)
            //     {
            //         int x = i-1;
            //         int y = j-1;
            //         int val = (x*x)+(y*y);
            //         if(val == d)
            //         {
            //             f = 1;
            //             break;
            //         }
            //     }
            //     if(f)
            //         break;
            // }
            // if(f)
            // {
            //     cout << n << " " << d << endl;
            //     break;
            // }
        // }
    }
}