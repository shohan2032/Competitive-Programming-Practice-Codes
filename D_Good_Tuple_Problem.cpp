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
int col[N];//for bipartite graph
bool bipartite;

void dfs(int u)//TC-->BigO(v+e).DFS is a recursive travers algorithm for greaph.
{
    vis[u] = true;
    fr(ad_list[u])
    {
        if(!vis[i])
        {
            col[i] = col[u] ^ 1;//changing the color of adjacent node of u.u 0 hole or adjacent node hobe 1
            dfs(i);
        }
        else
        {
            if(col[u] == col[i])
                bipartite = false;
        }
    }
}
void solve()
{
    int v,e;
    cin >> v >> e;
    vi u(e),vv(e);
    fr(u) cin >> i;
    fr(vv) cin>> i;
    for(int i = 0;i < e;i++){
        ad_list[u[i]].pb(vv[i]);
        ad_list[vv[i]].pb(u[i]);
    }
    bipartite = true;

    //connected graph hoile 1 theke call korlei hobe.
    // dfs(1);

    //for disconnected graph
    for(int i = 1;i <= v;i++)
    {
        if(!vis[i])
            dfs(i);
    }
    if(bipartite)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}   

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // auto st = clock();
    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    // cerr << 1.0*(clock()-st)/CLOCKS_PER_SEC << endl;
    return 0;
}
/*Problem_link
    https://www.spoj.com/problems/DIGOKEYS/ bfs diye shortes path er problem
*/