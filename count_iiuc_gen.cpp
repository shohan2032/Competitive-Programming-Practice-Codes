#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
 
 
int32_t main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int t = rnd.next(1,1000);
    cout << t <<endl;
    while(t--)
    {
        int n = rnd.next(1,100000);
        cout << n << endl;
        for(int i= 1;i <= n;i++)
        {
            char ch = rnd.next('a','z');
            cout << ch;
        }
        cout << endl;
    }
}
