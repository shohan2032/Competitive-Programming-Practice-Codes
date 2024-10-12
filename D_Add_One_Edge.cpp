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

const int N = 5e5 + 9;
vi ad_list[N];
bool vis[N];
ll path_no = 1;
int path[N];//for path between any two vertex
int check_path_available[N];
queue<int>q;
ll di[N];
ll dis[N];//disconnected graph a souce node theke onno kono node a path na thakle sei node er jonno output 0 hobe.
void bf(int u)
{
    q.push(u);
    vis[u] = true;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        fr(ad_list[u])
        {
            if(!vis[i]){
                q.push(i);
                di[i] = di[u] + 1;//source node theke jekono node a jauar shortest path,jodi tader moddhe kono path thake
                vis[i] = true;
            }
        }
    }
}
void bfs(int u)
{
    q.push(u);
    vis[u] = true;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        fr(ad_list[u])
        {
            if(!vis[i]){
                q.push(i);
                dis[i] = dis[u] + 1;//source node theke jekono node a jauar shortest path,jodi tader moddhe kono path thake
                vis[i] = true;
            }
        }
    }
}
void solve()
{
    int v1,v2,e;
    cin >> v1 >> v2 >> e;
    while(e--)
    {
        int u,v;
        cin>> u >>v;
        ad_list[u].pb(v);
        ad_list[v].pb(u);
    }
    bfs(v1+v2);
    for(int i = 1;i <= v1+v2;i++)
        vis[i] = false;
    bf(1);
    ll a = 0,b = 0;
    for(int i = 1;i <= v1+v2;i++)
    {
        a = max(dis[i],a);
        b = max(di[i],b);
    }
    cout << a+b+1 << endl;
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