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
#define loop1 for (i = 0; i < n; i++)
#define loop2 for (j = 0; j < n; j++)
#define fr(cont) for (auto &i : (cont))
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.rbegin(), cont.rend()
#define endl '\n'

// constants...
const double pi = acos(-1);
const ll mod = 100000007;//998244353
const int MXS = 2e5 + 5;
const ll MXI = 1e9 + 5;
const ll MXL = 1e18 + 5;
const ll INF = 1e9 + 5;
const ll INFLL = 1e18 + 5;
const ll eps = 1e-9;


int n,m,v[55],dp[55][1005],c[55];
int fun(int ind,int tar)
{
    if(tar==0)
        return 1;
    if(ind == 0)
        return 0;
    if(dp[ind][tar] != -1)
        return dp[ind][tar];
    int ans = fun(ind-1,tar);
    for(int i = 1;i <= c[ind];i++)
    {
        if(v[ind]*i <= tar)
            ans += fun(ind-1,tar-v[ind]*i);
        ans %= mod;
    }
    return dp[ind][tar] = ans;
}

void solve()
{
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        cin>> v[i];
    for(int i = 1;i <= n;i++)
        cin>> c[i];
    memset(dp,-1,sizeof dp);
    cout << fun(n,m) << endl;
}   

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // auto st = clock();
    int t = 1;
    cin >> t;
    for(int i = 1;i<= t;i++)
    {
        cout << "Case " << i << ": ";
        solve();
    }
    // cerr << 1.0*(clock()-st)/CLOCKS_PER_SEC << endl;
    return 0;
}
/*Problem_link

*/