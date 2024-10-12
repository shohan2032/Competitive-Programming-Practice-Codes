#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
#define ll long long
#define int ll
 
int32_t main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int t = inf.readInt(1, 100000, "t");
    inf.readEoln();
    for(int test = 1;test <= t;test++)
    {
        setTestCase(test);
        int n = inf.readInt(2, 1'000'000'000'000'000'000, "n");
        ensuref(n%2==0,"Value of N is odd for [testcase %d]", test);
        inf.readEoln();
    }
    inf.readEof();
}
