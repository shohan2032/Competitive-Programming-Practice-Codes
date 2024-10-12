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

const int N = 1e4 + 9;
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
    for(int i = 1;i <= v;i++)
    {
        ad_list[i].clear();
        vis[i] = false;
        col[i] = 0;
    }
    while(e--)
    {
        int u,v;
        cin>> u >>v;
        ad_list[u].pb(v);
        ad_list[v].pb(u);
    }
    bipartite = true;
    dfs(1);
    if(bipartite)
    {
        cout << "Bob" << endl;
        vi z,o;
        for(int i = 1;i <= v;i++)
        {
            if(col[i])
                o.pb(i);
            else
                z.pb(i);
        }
        for(int i = 1;i <= v;i++)
        {
            int a,b;
            cin>> a >> b;
            if(min(a,b) == 1)
            {
                if(o.size())
                {
                    cout << o.back() << " " << 1 << endl;
                    o.pop_back();
                }
                else
                {
                    cout << z.back() << " " << max(a,b) << endl;
                    z.pop_back();
                }
            }
            else
            {
                if(z.size())
                {
                    cout << z.back() << " " << 2 << endl;
                    z.pop_back();
                }
                else
                {
                    cout << o.back() << " " << 3 << endl;
                    o.pop_back();
                }
            }
        }
    }
    else
    {
        cout << "Alice" << endl;
        for(int i = 1;i <= v;i++)
        {
            cout << 1 << " " << 2 << endl;
            int a,b;
            cin >> a >> b;
        }
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
    https://www.spoj.com/problems/DIGOKEYS/ bfs diye shortes path er problem
*/