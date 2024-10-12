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

void solve()
{  
    int inf = 1e18; 
    string a,b;
    cin >> a >> b;
    int c[225][225];
    for(int i = 97;i <= 123;i++)
    {
        for(int j = 97;j <= 123;j++) 
            c[i][j] = inf;
    }
    int n;
    cin >>  n;
    while(n--)
    {
        char u,v;
        int wt;
        cin >> u >> v >> wt;
        int x = u;
        int y = v;
        c[x][y] = min(c[x][y],wt);
    }
    for(int k = 97;k <= 123;k++)
    {
        for(int i = 97;i <= 123;i++)
        {
            for(int j = 97;j <= 123;j++)
            {
                if(c[i][k] != inf and c[k][j] != inf)
                    c[i][j] = min(c[i][j],c[i][k]+c[k][j]);
            }
        }
    }
    if(a.size() != b.size())
        cout <<  -1 << endl;
    else
    {
        int ans = 0;
        string s = "";
        for(int i = 0;i < a.size();i++)
        {
            if(a[i] != b[i])
            {
                int x = a[i];
                int y = b[i];
                int temp = c[x][y];
                char ch = b[i];
                if(c[y][x] < c[x][y])
                {
                    temp = c[y][x];
                    ch = a[i];
                }
                for(int j = 97;j <= 123;j++)
                {
                    if(c[x][j] + c[y][j] < temp)
                    {
                        temp = c[x][j] + c[y][j];
                        ch = j;
                    }
                }
                if(temp == 1e18)
                {
                    cout << -1 << endl;
                    return;
                }
                ans += temp;
                s += ch;
            }
            else    
                s += a[i];
        }
        cout << ans << endl << s << endl;
    }
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

*/