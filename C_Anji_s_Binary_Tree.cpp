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

const int N = 3e5 + 9;
vi l[N],r[N];
int n;
string s;
bool leaf[N];
int ans = 1e18;
int par[N];
bool vis[N];
void dfs(int u,int cnt)//TC-->BigO(v+e)
{
    if(leaf[u])
    {
        ans = min(ans,cnt);
        return;
    }
    if(s[u-1] == 'L')
    {
        if(!l[u].empty())
            dfs(l[u].back(),cnt);
        if(!r[u].empty())
            dfs(r[u].back(),cnt+1);
    }
    if(s[u-1] == 'R')
    {
        if(!r[u].empty())
            dfs(r[u].back(),cnt);
        if(!l[u].empty())
            dfs(l[u].back(),cnt+1);
    }
    if(s[u-1] == 'U')
    {
        if(!l[u].empty()){
            dfs(l[u].back(),cnt+1);
        }
        if(!r[u].empty())
            dfs(r[u].back(),cnt+1);
    }
}

void solve()
{
    ans = 1e18;
    s.clear();
    cin >> n >> s;
    for(int i = 0;i <= n+5;i++)
    {
        vis[i] = false;
        par[i] = 0;
        leaf[i] = false;
        l[i].clear();
        r[i].clear();
    }
    for(int i = 1;i <= n;i++)
    {
        int lc,rc;
        cin>> lc >> rc;
        if(lc == 0 and rc == 0)
            leaf[i] = true;
        if(lc != 0){
            l[i].pb(lc);
            par[lc] = i;
        }
        if(rc != 0){
            r[i].pb(rc);
            par[rc] = i;
        }
    }
    dfs(1,0);
    cout << ans << endl;
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