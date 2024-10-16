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

const int N = 3e5 + 9;
// returns the longest proper prefix array of pattern p
// where lps[i]=longest proper prefix which is also suffix of p[0...i]
//prefix_function
vector<int> build_lps(string p) {//TC->O(|p|)
    int sz = p.size();
    vector<int> lps;
    lps.assign(sz + 1, 0);
    int j = 0;
    lps[0] = 0;
    for(int i = 1; i < sz; i++) 
    {
        while(j >= 0 && p[i] != p[j]) {
            if(j >= 1) j = lps[j - 1];
            else j = -1;
        }
        j++;
        lps[i] = j;
    }
    return lps;
}
vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    z[0] = 0;//or n
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
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
    string s,pp;
    getline(cin,s);
    getline(cin,pp);
    string ss = s;
    if(s.size() != pp.size())
    {
        cout << -1 << " " << -1 << endl;
        return;
    }
    vi z = z_function(pp+'#'+s);
    reverse(all(s));
    vi p = build_lps(s+'#'+pp);
    // dbg(z);
    // dbg(p);
    for(int i = s.size()+1,j = 0;i < z.size()-1;i++,j++)
    {
        if(z[i] >= 2)
        {
            int len = p[2*s.size()-j-1];
            int y = s.size() - len;
            if(j-1 >= 0 and ss[j-1] == ' ')
                j--;
            if(y-1 >= 0 and ss[y-1] == ' ')
                y--;
            // cout << z[i] << " " << j << " " << y << " " << p[2*s.size()-j-1] <<endl;
            if(j <= s.size()-len-1)
            {
                cout << j << " " << y << endl;
                return;
            }
        }
    }
    cout << -1 << " " << -1 << endl;
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