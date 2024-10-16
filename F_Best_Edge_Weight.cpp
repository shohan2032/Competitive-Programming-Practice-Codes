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

struct node
{
    int wt,u,v,id;
    node(int weight,int l,int r,int i)
    {
        wt = weight;
        u = l;
        v = r;
        id = i;
    }
};

int const N = 2e5+9;
int siz[N],parent[N];
vpi ad_list_for_mst[N];
int level[N];
int max_edge[N][31];
int up[N][31];

void dfs(int u,int par,int lvl)
{
    level[u] = lvl;
    fr(ad_list_for_mst[u])
    {
        if(i.first != par)
            dfs(i.first,u,lvl+1);
    }
}

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

//This function TC-->O(Nlog(N))
void binary_lifting(int src,int par)
{
    up[src][0] = par;
    for(int i = 1;i <= 20;i++)
    {
        if(up[src][i-1] == -1){
            up[src][i] = -1;
            max_edge[src][i] = -1;
        }
        else{
            up[src][i] =up[up[src][i-1]][i-1];
            max_edge[src][i] = max(max_edge[src][i-1],max_edge[up[src][i-1]][i-1]);
        }
    }
    fr(ad_list_for_mst[src])
    {
        if(i.first != par){
            max_edge[i.first][0] = i.second;
            binary_lifting(i.first,src);
        }
    }
}

int lift_node(int u,int jump)//jump hobe 2 er power akare
{
    if(u == -1 or jump == 0)
        return u;
    for(int i = 20;i >=0;i--)
    {
        if(jump >= (1 << i))
            return lift_node(up[u][i],jump-(1<<i));
    }
}

//TC-->O(log(n))
int lca(int u,int v)
{
    if(level[u] < level[v])//root theke jar lvl beshi tare u te rakhtesi
        swap(u,v);
    u = lift_node(u,level[u]-level[v]);//Now u and v are at the same level
    if(u == v)//dont be confused.we made the level same not u and v
        return u;
    for(int i = 20;i >= 0;i--)
    {
        if(up[u][i] != up[v][i])//jump from u to n1 and from v to n2 untill n1 != n2.when n1 == n2 then we reach from u and v to 1 step lower node of our desired lca node.
        {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return lift_node(u,1);//Now u is one step lower node of lca.so we just need 1 jump to reach in LCA.
}


int max_edge_in_the_cycle(int u,int v){
    if(level[u] < level[v])//root theke jar lvl beshi tare u te rakhtesi
        swap(u,v);
    int jump = level[u] - level[v];
    int res = 0;
    for(int i = 20;i >= 0;i--)
    {
        if(jump & (1 << i))
        {
            res = max(res,max_edge[u][i]);
            u = up[u][i];
        }
    }
    return res;
}

bool cmp(const node &A,const node &B)
{
    return A.wt < B.wt;
}

void solve()
{
    int n,q;
    cin >> n >> q;
    for(int i = 1 ;i <= n;i++)
        make(i);
    vector<node>edges;
    for(int i = 0;i < q;i++)
    {
        int u,v,wt;
        cin >> u >> v >> wt;
        edges.pb(node(wt,u,v,i));
    }
    sort(all(edges),cmp);
    // fr(edges)
    //     cout << i.u << " "<< i.v << " " << i.wt << " " << i.id <<endl;
    vi ans(q+5,-1);
    vi edge_taken_by_mst(q+5,0);
    int total_wt_of_mst = 0,cnt =0;
    fr(edges)
    {
        int wt = i.wt;
        int u = i.u;
        int v = i.v;
        int id = i.id;
        if(find(u) != find(v))
        {
            cnt++;
            total_wt_of_mst += wt;
            uni(u,v);
            ad_list_for_mst[u].pb(mp(v,wt));
            ad_list_for_mst[v].pb(mp(u,wt));
            edge_taken_by_mst[id] = 1;
        }
    }
    dfs(1,-1,0);
    binary_lifting(1,-1);
    fr(edges)
    {
        if(!edge_taken_by_mst[i.id])
        {
            int max_edge_val = 0;
            int u = i.u;
            int v = i.v;
            int lca_of_uv = lca(u,v);
            max_edge_val = max(max_edge_val,max_edge_in_the_cycle(lca_of_uv,u));
            max_edge_val = max(max_edge_val,max_edge_in_the_cycle(lca_of_uv,v));
            ans[i.id] = max_edge_val-1;
        }
        else
            ans[i.id] = (cnt == q?-1:i.wt);
    }
    for(int i = 0;i < q;i++)
        cout << ans[i] << " ";
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
    LCA with binary lifting+MST --> 
    https://codeforces.com/problemset/problem/609/E
*/