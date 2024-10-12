#include <bits/stdc++.h>

using namespace std;

#define db long long
#define ll long long
#define int ll
#define vi vector<int>
#define vs vector<string>
#define vl vector<int>
#define pi pair<int, int>
#define vpi vector<pair<int, int>>
#define vpl vector<pair<int, int>>
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

const ll mod = 998244353;

const int N = 1e5 + 9;
const int INF = 1e18;
vector<pair<int,int>>ad_list1[N],ad_list2[N];


vector<int> dijkstra(int source,vpi ad_list[])
{
    priority_queue<pi,vpi,greater<pi>> q;
    vector<bool>vis(N,0);
    vi dis(N,INF);
    dis[source] = 0;
    q.push(mp(0,source));
    
    while(!q.empty())
    {
        pi top = q.top();
        int u = top.second;
        q.pop();
        if(vis[u])
            continue;
        vis[u] = 1;
        for(auto &child: ad_list[u])
        {
            int v = child.first;
            int wt = child.second;
            if(dis[u] + wt < dis[v])
            {
                dis[v] = dis[u]+wt;
                q.push(mp(dis[v],v));
            }
            
        }
    }
    return dis;
}

void solve()
{
    int v,m,x,q,s,t;
    cin >> v >> m >> x >> q;
    for(int i = 1;i <= v;i++)
        ad_list1[i].clear(),ad_list2[i].clear();
    for(int i = 1;i <= m;i++)
    {
        int u,v,w;
        cin>> u >> v >> w;
        ad_list1[u].pb(mp(v,w));
        ad_list2[v].pb(mp(u,w));
    }
    auto dis1 = dijkstra(x,ad_list2);//x to s
    auto dis2 = dijkstra(x,ad_list1);//x to t
    while(q--)
    {
        cin>> s >> t;
        if(dis1[s] + dis2[t] >= INF)
            cout << "Be seeing ya, John" << endl;
        else
            cout << dis1[s] + dis2[t] << endl;
    }
}   

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // auto st = clock();
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t;i++)
    {
        cout << "Case " << i << ":" << endl;
        solve();
    }
    // cerr << 1.0*(clock()-st)/CLOCKS_PER_SEC << endl;
    return 0;
}
/*Problem_link
    https://codeforces.com/problemset/problem/20/C (getting shortest path between 1 and n in a weighted graph)

    https://codeforces.com/contest/450/problem/D
*/