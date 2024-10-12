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

const int N = 3e5 + 9;
vi ad_list[N];
bool vis[N];
ll path_no = 1;
ll trackTotalPath[N];
map<int,vi>p;
ll dfs(int u)//TC-->BigO(v+e)
{
    p[path_no].pb(u);
    vis[u] = true;
    fr(ad_list[u]){
        if(!vis[i]){
            trackTotalPath[u] +=dfs(i);
        }
    }
    path_no++;
    return trackTotalPath[u];
}

void solve()
{
    int n;
    cin >> n;
    int r = 0;
    for(int i = 1;i <= n;i++)
    {
        int x;
        cin >> x;
        if(x == i)
            r = x;
        else        
        {
            ad_list[x].pb(i);
            ad_list[i].pb(x);
        }
    }
    for(int i  = 1;i <= n;i++)
    {
        if(ad_list[i].size() == 1 and i != r)
            trackTotalPath[i] = 1;
    }
    dfs(r);
    cout << max(1ll,trackTotalPath[r]) << endl;
    fr(p)
    {
        cout << i.second.size() << endl;
        for(auto &j:i.second)
            cout << j << " ";
        cout << endl;
    }
    cout << endl;
    for(int i = 1;i <= n;i++)
    {
        vis[i] = false;
        ad_list[i].clear();
        path_no = 1;
        trackTotalPath[i] = 0;
    }
    p.clear();
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