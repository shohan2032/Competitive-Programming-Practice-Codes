#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
bool vis[N];
vector<int> g[N];
int f = 0;
int dis[N];
queue<int>q;
void dfs(int u,int p){
    vis[u] = 1;
    for (auto v: g[u]){
        if(vis[v] and v == p)
            continue;
        if(vis[v]){
            if(!f)
                f = v;
        }
        else
            dfs(v,u);
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
        for (auto i: g[u])
        {
            if(!vis[i]){
                q.push(i);
                dis[i] = dis[u] + 1;
                vis[i] = true;
            }
        }
    }
}

void solve()
{
    int n,m,v;
    cin >>n >> m >> v;
    for(int i = 1;i <= n;i++)
    {
        vis[i] = 0;
        dis[i] = 0;
        g[i].clear();
    }
    for (int i = 1; i <= n; i++) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    f = 0;
    dfs(v,0);
    if(f and m != v)
    {
        for(int i = 1;i <= n;i++)
            vis[i] = 0;
        bfs(f);
        if(dis[v] < dis[m])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    else
        cout<< "NO" << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
