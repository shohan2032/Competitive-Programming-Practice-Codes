#include <bits/stdc++.h>

using namespace std;

#define db long long
#define ll long long
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

const int N = 2e5 + 9;
vi ad_list[N];
bool vis[N];
ll s = 0;
ll ans[N],coin[N];ad_list_for_mst
ll dfs(int u)//TC-->BigO(v+e)
{
    vis[u] = true;
    fr(ad_list[u]){
        if(!vis[i])
           ans[u] += dfs(i);
        else
            ans[u] += ans[i];
    }
    ans[u] = min(coin[u],ans[u]);
    return ans[u];
}

void solve()
{
    ll n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++)
        cin >> coin[i];
    ll p[n+5] = {};
    for(int i = 1;i <= k;i++)
    {
        int x;
        cin >> x;
        coin[x] = 0;
        p[x] = 1;
    }
    for(int i = 1;i <= n;i++)
    {
        int m = 0;
        cin >> m;
        if(m == 0)
        {
            ad_list[i].pb(i);
            if(p[i])
                ans[i]=0;
            else    
                ans[i] = coin[i];
            vis[i] = true;
        }
        else
        {
            while(m--)
            {
                int x;
                cin >> x;
                ad_list[i].pb(x);
            }
        }
    }
    for(int i = 1;i <= n;i++)
    {
        if(!vis[i])
            dfs(i);
    }
    for(int i = 1;i <= n;i++)
    {
        cout << ans[i] << " ";
        vis[i] = false;
        ad_list[i].clear();
        coin[i] = 0;
        ans[i] = 0;
    }
    cout << endl;
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