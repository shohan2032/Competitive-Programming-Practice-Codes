#include <bits/stdc++.h>

using namespace std;

#define db long long
#define ll long long
#define int ll
#define vi vector<int>
#define vs vector<string>
#define vpi vector<pair<int, int>>
#define vpd vector<pair<double, double>>
#define vps vector<pair<string, string>>
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
#define fr(cont) for (auto &i : (cont))
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.rbegin(), cont.rend()


void solve()
{
    int n;
    cin >> n;
    int o =0,e = 0;
    vi vc(n);
    fr(vc)
    {
        cin >> i;
        if(i & 1)
            o++;
        else
            e++;
    }
    if(e == n)
    {
        cout << "YES" << endl;
        return;
    }
    if(o == n)
    {
        if(o & 1)
            cout << "NO" << endl;
        else
            cout<< "YES" << endl;
        return;
    }
    if(o & 1)
        cout << "NO" << endl;
    else
        cout<< "YES" << endl;
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
/*Problem_link

*/