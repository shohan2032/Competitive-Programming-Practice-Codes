#include <bits/stdc++.h>

using namespace std;
#define db long long
#define ll long long
#define int ll
#define vi vector<int>
#define vs vector<string>
#define vpi vector<pair<int, int>>
#define vpd vector<pair<double, double>>
#define vps vector<pair<string, string>>
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
#define fr(cont) for (auto &i : (cont))
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.rbegin(), cont.rend()

int const N = 3e5+9;
int siz[N],parent[N];

//overall TC of DSU is constant.O(alpha(N)) --> reversed ackerman function..It increase very slowly.That is almost N.
void make(int n)//add new node to our current sets
{
    parent[n] = n;
    siz[n] = 1;
}

int find(int n)//return the root of that set where the node n belonged to.
{
    if(parent[n] == n)
        return n;
    return parent[n] = find(parent[n]);//path compression
}

void uni(int a,int b)//set node a and b to the same group
{
    a = find(a);//a node er root ta finding
    b = find(b);//b node er root ta finding

    if(a != b)//when both a and b are not belonged to the same set
    {
        //union by size
        //We will add small tree to the big tree so that the depth of the tree will be smaller
        if(siz[a] < siz[b])
            swap(a,b);
        parent[b] = a;
        siz[a] += siz[b];
    }
}
bool vis[N];
vi path;
vi g[N];
int f;
void dfs(int s,int d)
{
    // cout <<s << "--> ";
    vis[s] = 1;
    if(s == d)
    {
        f = 1;
        path.pb(s);
        return;
    }
    path.pb(s);
    fr(g[s])
    {
        if(vis[i] or f)
            continue;
        dfs(i,d);
    }
    if(!f)
        path.pop_back();
}
void solve()
{
    int n,q;
    cin >> n >> q;
    for(int i = 1 ;i <= n;i++)
    {
        make(i);
        vis[i] = false;
        g[i].clear();
    }
    vector<pair<int,pair<int,int>>>edges;
    while(q--)
    {   
        int u,v,w;
        cin>> u >> v >>w;
        edges.pb(mp(w,mp(u,v)));
    }
    sort(rall(edges));
    int s_n,e_n,wt;
    fr(edges)
    {
        int u = i.second.first;
        int v = i.second.second;
        int w = i.first;
        if(find(u) == find(v))
        {
            s_n = u;
            e_n = v;
            wt = w;
            g[u].pb(v);
            g[v].pb(u);
        }
        else
        {
            uni(u,v);
            g[u].pb(v);
            g[v].pb(u);
        }
    }
    // cout << s_n << " " << e_n << endl;
    dfs(s_n,e_n);
    cout << wt << " " << path.size() << endl;
    fr(path)cout << i << " ";
    cout <<endl;
    path.clear();
    f = 0;
}   

int32_t main()
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
        https://codeforces.com/problemset/problem/1213/G
        https://codeforces.com/contest/25/problem/D
    https://codeforces.com/contest/1559/problem/D1
    https://codeforces.com/contest/1559/problem/D2
     https://codeforces.com/problemset/problem/277/A
     https://codeforces.com/contest/977/problem/E
    https://codeforces.com/problemset/problem/1167/C
*/