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
    set<string>st;
    for(int i = 2;i <= 100;i++)
    {
        int p = 1;
        for(int j = 2;j*j <= i;j++)
        {
            if(i % j == 0)
            {
                p = 0;
                break;
            }
        }
        if(p){
            string ss = to_string(i);
            if(ss.size() >= 2)
                st.insert(ss);
        }
    }
    string s;
    cin >>s;
    map<char,int>mp;
    for(int i = 0;i < s.size();i++)
        mp[s[i]] = i;
    fr(st)
    {
        string ss = i;
        if(mp[ss[1]] > mp[ss[0]])
        {
            cout << ss << endl;
            return;
        }
    }
    cout << -1 << endl;
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