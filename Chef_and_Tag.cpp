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
int depth[N],le[N],cnt[N];
int dfs(int u,ll p)//TC-->BigO(v+e)
{
    if(le[u])
        cnt[u]++;
    depth[u] = depth[p]+1;
    fr(ad_list[u]){
        if(i != p)//this line can be deleted if we delete the 47th line also
            cnt[u] += dfs(i,u);
    }
    return cnt[u];
}

void solve()
{

    int v,e;
    cin >> v;
    e = v-1;
    while(e--)
    {
        int u,v;
        cin>> u >>v;
        ad_list[u].pb(v);
        ad_list[v].pb(u);
    }
    int l = 0,min_d = 1e9+5;
    for(int i = 2;i <= v;i++)
    {
        if(ad_list[i].size() == 1)
        {
            le[i] = 1;
            l++;
        }
    }
    dfs(1,0);
    for(int i = 2;i <= v;i++)
    {
        if(le[i])
            min_d = min(min_d,depth[i]);

    }
    int ans = 0;
    for(int i= 1;i <= v;i++)
    {
        if(min_d-depth[i] <= depth[i])
            ans = max(ans,l);
        else
            ans = max(ans,l-1);
        ad_list[i].clear();
        cnt[i] = 0;
        depth[i] = 0;
        le[i] = 0;
    }
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
    https://www.spoj.com/problems/DIGOKEYS/ bfs diye shortes path er problem
*/