#include <bits/stdc++.h>

using namespace std;

string s = "FBFFBFFBFBFFBFFBFBFFB";
void solve()
{
    int n;
    cin >> n;
    string ss;
    cin >> ss;
    if(s.find(ss) != string::npos)
        cout << "YES" << endl;
    else
        cout << "NO" <<endl;
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