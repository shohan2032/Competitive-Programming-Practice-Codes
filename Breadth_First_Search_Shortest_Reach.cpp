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
#define mo(a, b) (((a) % (b)) + (b)) % (b)
#define endl '\n'

const int N = 1005;
vector<int> adList[N];
bool vis[N];
int dis[N];
void bfs(int u)
{
    vis[u] = true;
    dis[u] = 0;
    queue<int>pq;
    pq.push(u);
    while(!pq.empty())
    {
        int cur = pq.front();
        pq.pop();
        for(auto &j:adList[cur])
        {
            if(!vis[j])
            {
                vis[j] = true;
                dis[j] = 6+dis[cur];
                pq.push(j);
            }
        }
    }
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
    int n,m;
    cin>> n >> m;
    for(int i = 1;i <= n;i++)
    {
        vis[i] = false;
        adList[i].clear();
        dis[i] = 1e9;
    }
    while(m--)
    {
        int u,v;
        cin>> u >> v;
        adList[u].pb(v);
        adList[v].pb(u);
    }
    int s;
    cin>>s;
    bfs(s);
    for(int i = 1;i <= n;i++)
    {
        if(i != s)
        {
            if(dis[i] == 1e9)
                cout << -1 << " ";
            else
                cout << dis[i] << " ";
        }
    }
    cout << endl;
}   

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // auto st = clock();
    int t = 1;
    cin >> t;
    for(int i = 1;i <= t;i++)
    {
        // cout << "Case " << i << ": ";
        solve();
    }

    // cerr << 1.0*(clock()-st)/CLOCKS_PER_SEC << endl;
    return 0;
}
/*Problem_link
    https://www.hackerrank.com/contests/appifylab-intern-batch-2/challenges/red-knights-shortest-path/problem
*/