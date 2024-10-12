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

    int n,m;
    cin >> n >> m;
    vi a(n),b(m);
    fr(a) cin >> i;
    fr(b) cin >> i;
    int o_v = b[0];
    for(int i = 1;i < m;i++)
        o_v |= b[i];
    int cnt = 0;
    for(int i = 0;i < n;i++){
        cnt ^= a[i];
        a[i] |= o_v;
    }
    int x_v = a[0];
    for(int i = 1;i < n;i++)
        x_v ^= a[i];
    cout << min(x_v,cnt) << " " << max(cnt,x_v) << endl;
    
}   

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
