#include <bits/stdc++.h>

using namespace std;

#define db long long
#define ll long long
#define int ll
#define vi vector<int>
#define vs vector<string>
#define vl vector<ll>
#define pii pair<int, int>
#define vpi vector<pair<int, int>>
#define vpl vector<pair<ll, ll>>
#define vpd vector<pair<double, double>>
#define vps vector<pair<string, string>>
#define mp(x, y) make_pair(x, y)
#define f first
#define s second
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
#define fr(cont) for (auto &i : (cont))
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.rbegin(), cont.rend()

void solve()
{
    int n,m ;
    cin >> n >> m;
    vi mark(n+2,n+1);
    for(int i = 1;i <= m;i++)
    {
        int x,y;
        cin>> x >>y;
        if(x > y)
            swap(x,y);
        mark[x] = min(mark[x],y);
    }
    // for(int i = 1;i <= n;i++)
    //     cout << mark[i] << " " ;
    for(int i = n-1;i >= 1;i--)
        mark[i] = min(mark[i],mark[i+1]);
    // cout << endl;
    // for(int i = 1;i <= n;i++)
    //     cout << mark[i] << " " ;
    ll ans = 0;
    for(int i = 1;i <= n;i++)
        ans += mark[i] - i;
    cout << ans << endl;
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