#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    if(n % 3 == 0)
        cout << "Second" << endl;
    else
        cout << "First" << endl;
}   

int32_t main()
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