#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n = 4;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            int a = i-1;
            int b = j-1;
            int d = (a*a)+(b*b);
            cout << i << " " << j << " " << d << endl;
        }
    }
}
