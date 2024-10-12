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
        int n = inf.readInt(1, 100, "n");
        for(int i = 1;i <= n;i++)
        {
            char ch = inf.readChar();
            if(i == 1)
                ensuref(ch >= '1' and ch <= '9',"char is not perfect for [testcase %d]", test);
            else
                ensuref(ch >= '0' and ch <= '9',"char is not perfect for [testcase %d]", test);
        }
        inf.readEoln();
    }
    inf.readEof();
}
