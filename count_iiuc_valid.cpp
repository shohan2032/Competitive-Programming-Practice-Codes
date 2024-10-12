#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
#define ll long long
#define int ll
 
int32_t main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int t = inf.readInt(1, 1000, "t");
    inf.readEoln();
    for(int test = 1;test <= t;test++)
    {
        setTestCase(test);
        int n = inf.readInt(1, 1'000'00, "n");
        inf.readEoln();
        for(int i = 1;i <= n;i++)
        {
            char ch = inf.readChar();
            ensuref(ch >= 'a' and ch <= 'z',"Value of D is not perfect for [testcase %d]", test);
        }
        inf.readEoln();
    }
    inf.readEof();
}
