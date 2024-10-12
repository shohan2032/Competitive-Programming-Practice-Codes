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
const int INF = 1e18;

vector<int> dijkstra(int source,vpi ad_list[])
{
    priority_queue<pi,vpi,greater<pi>> q;
    bool vis[N];
    memset(vis,0,sizeof(vis));
    vi dis(N,INF);

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
    return dis;
}

void solve()
{

    int v,a,b,c;
    cin >> v >> a >> b >> c;
    vector<pair<int,int>>list1[v+ 5],list2[v + 5];
    for(int i = 1;i <= v;i++)
    {
        for(int j = 1;j <= v;j++){
            int x;
            cin>>x;
            if(i != j)
            {
                int cc = x*a;
                int t = x * b + c;
                list1[i].pb(mp(j,cc));
                list2[i].pb(mp(j,t));
            }
        }
    }
    auto dis1 = dijkstra(1,list1);
    auto dis2 = dijkstra(v,list2);
    int ans = INF;
    for(int i= 1;i <= v;i++){
        ans = min(ans,dis1[i]+dis2[i]);
        // cout << dis1[i] << " " << dis2[i] << " " << ans <<  endl;
    }
    cout << ans << endl;
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
    https://codeforces.com/problemset/problem/20/C (getting shortest path between 1 and n in a weighted graph)

    https://codeforces.com/contest/450/problem/D
    https://codeforces.com/contest/567/problem/E(source theke jekeono vertex a jauar total koita shortest path ache seita ei problem a use hoiyeche

    
*/