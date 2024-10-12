#include <bits/stdc++.h>

using namespace std;

//Debug Function-->works for vector,map,set(dbg(stl_name)),,arrar(dbg(array_name,range))
template < typename F, typename S >ostream& operator << ( ostream& os, const pair< F, S > & p ) {return os << "(" << p.first << ", " << p.second << ")";}
template < typename T >ostream &operator << ( ostream & os, const vector< T > &v ) {os << "{";for(auto it = v.begin(); it != v.end(); ++it) {if( it != v.begin() ) os << ", ";os << *it;}return os << "}";}
template < typename T >ostream &operator << ( ostream & os, const set< T > &v ) {os << "[";for(auto it = v.begin(); it != v.end(); ++it) {if( it != v.begin() ) os << ", ";os << *it;}return os << "]";}
template < typename T >ostream &operator << ( ostream & os, const multiset< T > &v ) {os << "[";for(auto it = v.begin(); it != v.end(); ++it) {if( it != v.begin() ) os << ", ";os << *it;}return os << "]";}
template < typename F, typename S >ostream &operator << ( ostream & os, const map< F, S > &v ) {os << "[";for(auto it = v.begin(); it != v.end(); ++it) {if( it != v.begin() ) os << ", ";os << it -> first << " = " << it -> second ;}return os << "]";}
#define dbg(args...) do {cerr << #args << " : "; arif(args); } while(0)
clock_t tStart = clock();
#define timeStamp dbg("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)
void arif () {cerr << endl;}
template <typename T>void arif( T a[], int n ) {for(int i = 0; i < n; ++i) cerr << a[i] << ' ';cerr << endl;}
template <typename T, typename ... hello>void arif( T arg, const hello &... rest) {cerr << arg << ' ';arif(rest...);}

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
#define mo(a, b)	(((a) % (b)) + (b)) % (b)

int const N = 3e5+9;
int siz[N],parent[N];
vi ad_list[N];
bool vis[N];
int cnt[N];
int f,n;
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

void dfs(int u)
{
    // cout << u << endl;
    vis[u] = true;
    f += cnt[u];
    fr(ad_list[u])
    {
        if(!vis[i])
            dfs(i);
    }
}

int check(vector<pair<string,string>>vc)
{
    map<string,int>g,w;
    int c = 0;
    for(int i = 0;i < vc.size();i++)
    {
        string a,b;
        a = vc[i].first;
        b = vc[i].second;
        if(!g.count(a))
        {
            c++;
            g[a] = c;
        }
        if(!w.count(b))
        {
            c++;
            w[b] = c;
        }
    }
    for(int i = 1;i <= c;i++)
    {
        vis[i] = false;
        cnt[i] = 0;
        siz[i] = 0;
        parent[i] = 0;
        ad_list[i].clear();
        make(i);
    }
    fr(vc)
    {
        int u = g[i.first];
        int v = w[i.second];
        cnt[u]++;
        cnt[v]++;
        ad_list[u].pb(v);
        ad_list[v].pb(u);
        uni(u,v);
        // cout << u << " " << v << endl;
    }
    int ans = 0;
    for(int i = 1;i <= c;i++)
    {
        if(find(i) == i)
        {
            // cout << i << endl;
            f = 0;
            dfs(i);
            // cout << f << endl;
            ans = max(ans,f/2);
        }
    }
    return n-ans;
}

void solve()
{
  /*
    1. Think Greedy
    2. Think Brute Force
    3. Think solution in reverse order
    4. Think DP [ check constraints carefully ]
    5. Check base cases for DP and prove solution for Greedy
    6. Think Graph
  */ 
    cin>> n;
    vector<pair<string,string>>vc,v;
    for(int i = 1;i <= n;i++)
    {
        string a,b;
        cin >> a >> b;
        vc.pb(mp(a,b));
    }
    int ans = 1e18;
    for(int mask=1;mask<(1<<n);mask++)
    {
        for(int i=0;i<n;i++)
        {
            if(mask & (1<<i))
                v.pb(vc[i]);
                // cout << vc[i].first << " "<< vc[i].second << endl;
        }
        ans = min(ans,check(v));
        v.clear(); 
    }
    cout<< ans << endl;
    
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