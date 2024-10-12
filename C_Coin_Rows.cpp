#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve()
{
    int n,x;
    cin >> n >> x;
    int r = 0,c = 0;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            int a = i-1;
            int b = j-1;
            int d = (a*a)+(b*b);
            if(x == d)
            {
                r = a;
                c = b;
                break;
            }
        }
        if(r)
            break;
    }
    int ans = 1e9;
    ans = min(ans,2*(n-1));
    ans = min(ans,r+c+1);
    cout << ans << endl;
}   

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // auto st = clock();
    int t = 1;
    cin >> t;
    while (t--)
        solve();

    // cerr << 1.0*(clock()-st)/CLOCKS_PER_SEC << endl;
    return 0;
}
/*Problem_link

*/