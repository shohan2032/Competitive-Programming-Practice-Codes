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

int cx[] = {-2,-2,0,2,2,0};
int cy[] = {-1,1,2,1,-1,-2};
int n;
bool valid(int x,int y)
{
    return (x >= 0 and x < n) and (y >= 0 and y < n);
}
void bfs(int sx,int sy,int dx,int dy)
{
    queue<pair<int,int>>pq;
    pq.push({sx,sy});

    int vis[205][205];
    memset(vis,0,sizeof vis);
    vis[sx][sy] = 1;

    int moveNo[205][205];
    memset(moveNo,-1,sizeof moveNo);

    vector<string>possibleMoves = {"UL","UR","R","LR","LL","L"};

    while(!pq.empty())
    {
        auto cur = pq.front();
        pq.pop();
        for(int i = 0;i < 6;i++)
        {
            int x = cur.first + cx[i];
            int y = cur.second + cy[i];
            if(valid(x,y) and !vis[x][y])
            {
                pq.push({x,y});
                vis[x][y] = 1;
                moveNo[x][y] = i;
            }
        }
    }
    vector<string>ans;
    while(moveNo[dx][dy] != -1)
    {
        int moveTaken = moveNo[dx][dy];
        ans.pb(possibleMoves[moveTaken]);
        dx -= cx[moveTaken];
        dy -= cy[moveTaken];
    }
    if(ans.size())
    {
        cout << ans.size() << endl;
        reverse(all(ans));
        fr(ans)
            cout << i << " ";
    }
    else
        cout << "Impossible" << endl;
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
    int sx,sd,dx,dy;
    cin>> n >> sx >> sd >> dx >> dy;
    bfs(sx,sd,dx,dy);
}   

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // auto st = clock();
    int t = 1;
    // cin >> t;
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