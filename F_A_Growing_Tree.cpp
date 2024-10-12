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

const int N = 5e5 + 9;
int a[N];
int discovery_time[N];
vi ad_list[N];
vpi add_q[N];
int ans[N];
int n;
struct ST {
    #define lc (n << 1)
    #define rc ((n << 1) + 1)
    int t[4*N],lazy[4*N];
    ST(){
        memset(t,0,sizeof(t));
        memset(lazy,0,sizeof(lazy));
    }

    //parent er main value and child gulor lazy value update korar function
    inline void push(int n,int b,int e)//change this
    {
        if(lazy[n] == 0)
            return;
        t[n] = t[n] + lazy[n];//parent node er value update
        if(b != e)
        {
            lazy[lc] = lazy[lc] + lazy[n];//left child er lazy value update
            lazy[rc] = lazy[rc] + lazy[n];//right child er lazy value update
        }
        lazy[n] = 0;//jehetu parent node er child er lazy value update kore pelsi so parent er lazy 0 kore dite hobe
    }

    //value merge kore return korbe query er jonno
    inline int combine(int a,int b)//change this 
    {
        return a+b;
    }

    //parent node er value save korar function
    inline void pull(int n)//change this
    {
        t[n] = t[lc] + t[rc];
    }

    //building the tree 
    inline void build(int n,int b,int e)
    {
        lazy[n] = 0;//change this
        if(b == e)
        {
            t[n] = a[b];
            return;
        }
        int mid = (b+e)/2;
        build(lc,b,mid);
        build(rc,mid+1,e);
        pull(n);
    }

    //updating the value in a segment
    inline void upd(int n,int b,int e,int i,int j,int x)
    {
        push(n,b,e);
        if(e < i or b > j)
            return;
        if(b >= i and e <= j)
        {
            lazy[n] = x;//set lazy
            push(n,b,e);//ei line na korleo hobe
            return;
        }
        int mid = (b+e)/2;
        upd(lc,b,mid,i,j,x);
        upd(rc,mid+1,e,i,j,x);
        pull(n);
    }

    inline int query(int n,int b,int e,int i,int j)
    {
        push(n,b,e);
        if(e < i or b > j)
            return 0;
        if(b >= i and e <= j)
            return t[n];
        int mid = (b+e)/2;
        return combine(query(lc,b,mid,i,j),query(rc,mid+1,e,i,j));
    }
}t;

void dfs(int u)
{
    fr(add_q[u])
        t.upd(1,1,n,i.first,i.first,i.second);
    ans[u] = t.query(1,1,n,discovery_time[u],n);//or discovery time theke n pojjonto je shokol add q or parent and or nijer jonno eshece tader value ei or jonno add hobe.
    // cout << u << " " << ans[u] << endl;
    fr(ad_list[u])
        dfs(i);
    fr(add_q[u])
        t.upd(1,1,n,i.first,i.first,-i.second);//particular kono node er jonno add_q gula contibute korbe only for it's add_list.then we don't need it's add_q.But if we keep it in segment tree,then there have a possibility of over count for other nodes.Check test case - 3
}

void solve()
{
    cin >> n;
    int total_node = 1;
    for(int i = 1;i <= n;i++)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int x;
            cin>> x;
            ad_list[x].pb(++total_node);
            discovery_time[total_node] = i;
        }
        else
        {
            int x,val;
            cin >> x >> val;
            add_q[x].pb(mp(i,val));
        }
    }
    dfs(1);
    for(int i= 1;i <= total_node;i++)
        cout << ans[i] << " ";
    cout << endl;
    for(int i= 1;i <= n;i++)
    {
        ad_list[i].clear();
        add_q[i].clear();
        discovery_time[i] = 0;
        ans[i] = 0;
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
    while (t--)
        solve();

    // cerr << 1.0*(clock()-st)/CLOCKS_PER_SEC << endl;
    return 0;
}
/*Problem_link

*/