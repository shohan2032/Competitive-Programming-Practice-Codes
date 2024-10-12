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

const int N = 2e5 + 9;
const int INF = 1e9;
vector<pair<int,int>>ad_list[N];
vi dis(N,INF);
bool vis[N];
priority_queue<pi,vpi,greater<pi>> q;
void dijkstra(int source)
{
    dis[source] = 0;
    q.push(mp(0,source));//jehetu amader minimum wt er node ta ke age process korte hobe tai q te always 1st ta wt ,2nd ta node push hobe.tahole wt er upor sorted thakbe.
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
            int v = child.first;//v node ta....u theke jeita te jacche
            int wt = child.second;//u theke v te jauar cost
            if(dis[u] + wt < dis[v])
            {
                dis[v] = dis[u]+wt;
                q.push(mp(dis[v],v));
            }
        }
    }
}

void solve()
{
    int v,e;
    cin >> v >> e;
    while(e--)
    {
        int u,v,wt;
        cin >> u >> v >>wt;
        ad_list[u].pb(mp(v,wt));
    }
    int source;
    cin>> source;
    // for(int i = 1;i <= v;i++)//printing ad_list
    // {
    //     int x = i;
    //     fr(ad_list[i])
    //         cout << x << " " <<  i.first << " " << i.second << endl;
    // }
    dijkstra(source);
    for(int i = 1;i <= v;i++)
        cout << dis[i] << " ";
}   

int32_t main()
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
    https://codeforces.com/problemset/problem/20/C
    (getting shortest path between 1 and n in a weighted graph)
*/