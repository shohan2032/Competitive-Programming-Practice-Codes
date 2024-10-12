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
ll ans = 0;
map<pair<int,int>,int>mp;
void dfs(int u,ll parent_po,ll iteration)//TC-->BigO(v+e)
{
    ans = max(iteration,ans);
    vis[u] = true;
    fr(ad_list[u]){
        if(!vis[i])
        {
            if(mp[{u,i}] < parent_po)
                dfs(i,mp[{u,i}],iteration+1);
            else
                dfs(i,mp[{u,i}],iteration);
        } 
    }
}

void solve()
{
    int v,e;
    cin>> v;
    e = v-1;
    ll i = 1;
    while(e--)
    {
        int u,v;
        cin >> u >> v;
        mp[{u,v}] = i;
        mp[{v,u}] = i;
        ad_list[u].pb(v);
        ad_list[v].pb(u); 
        i++;
    }
    dfs(1,0,1);
    cout << ans << endl;
    mp.clear();
    ans = 0;
    for(int i =1;i <= v;i++)
    {
        ad_list[i].clear();
        vis[i]= false;
    }
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