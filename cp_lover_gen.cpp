
#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
#define ll long long
#define int ll
 
 
int32_t main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int t = rnd.next(10000,10000);
    cout << t <<endl;
    while(t--)
    {
        int n = rnd.next(3,1000'000'000'000'000'000);
        if(n&1)
            n--;
        cout << n << endl;
    }
}
