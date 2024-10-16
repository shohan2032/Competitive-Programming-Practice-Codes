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

// constants...
const double pi = acos(-1);
const ll mod = 1000000007;
const int MXS = 2e5 + 5;
const ll MXI = 1e9 + 5;
const ll MXL = 1e18 + 5;
const ll INF = 1e9 + 5;
const ll INFLL = 1e18 + 5;
const ll eps = 1e-9;

// functions...
ll gcd(ll a, ll b){while (b){a %= b;swap(a, b);}return a;}
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }
ll ncr(ll a, ll b){ll x = max(a - b, b), ans = 1;for (ll K = a, L = 1; K >= x + 1; K--, L++){ans = ans * K;ans /= L;}return ans;}
ll egcd(ll a, ll b, ll &x, ll &y){if (a == 0){x = 0;y = 1;return b;}ll x1, y1;ll d = egcd(b % a, a, x1, y1);x = y1 - (b / a) * x1;y = x1;return d;}
// ll fact[2000005];
// ll ncr_mod(ll n,ll r) {return (((fact[n]*inverse_mod(fact[r]))%mod)*inverse_mod(fact[n-r]))%mod;}
db pytha(db x1, db x2, db y1, db y2) { return sqrt((pow((x2 - x1), 2)) + (pow((y2 - y1), 2))); } /// for two ending points pythagoras law
double make_radian(double x) { return (x * pi) / 180; }
double make_degree(double x) { return (x * 180) / pi; }
ll binmul(ll a, ll b, ll p){ll res = 0ll;while (b){if (b & 1)res = (res + a) % p, b--;else a = (a + a) % p, b /= 2;}return res;} //(a*b)%p
ll binpow(ll a, ll b, ll p){ll res = 1ll;while (b){if (b & 1)res = binmul(res, a, p), b--;else a = binmul(a, a, p), b /= 2;}return res;} //(a^b)%p
ll inverse(ll a, ll p) { return binpow(a, p - 2, p); } //(a^-1)%p == (a^p-2)%p
string decToBinary(int n){string s;int i = 0;while (n > 0){s = to_string(n % 2) + s;n = n / 2;i++;}return s;}
ll binaryToDecimal(string n){string num = n;ll dec_value = 0;int base = 1;int len = num.length();for (int i = len - 1; i >= 0; i--){if (num[i] == '1')dec_value += base;base = base * 2;}return dec_value;}
ll factorial(int n){long long fact = 1;  int md = 998244353;for (int i = 1; i <= n; i++){fact = (fact * i) % md;}return fact;}
void substring(string s){for (int i = 0; i <= s.size(); i++){for (int j = 0; j <= s.size() -i; j++){int l = j + i - 1;for (int k = i; k <= l; k++)cout << s[k];cout << endl;}}}
void permutation(vector<ll>v){sort(all(v));cout << "All possible permutations with the elements:\n";do{for(int i = 0;i < v.size();i++)cout << v[i] << " ";cout << endl;}while (next_permutation(all(v)));}//total permutation will be n!
bool powerOftwo(ll x){if(x == 0)return false;else return !(x&(x-1));}
ll powss(ll a, ll p){if(p==0) return 1;if(p==1) return a;else if(p&1) {return a*powss(a*a,p/2);}else {return powss(a*a,p/2);}}

const int N = 2e6 + 9, p1 = 137, p2 = 277, mod1 = 1e9 + 7, mod2 = 1e9 + 9;
pair<int, int> pw[N], ipw[N], a[N];

int bin(int x, int y, int mod) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = 1LL * ans * x % mod;
        x = 1LL * x * x % mod;
        y >>= 1;
    }
    return ans;
}
 
 
void precal() {
    pw[0] = {1, 1};
    for (int i = 1; i < N; i++) {
        pw[i].first = 1LL * pw[i - 1].first * p1 % mod1;
        pw[i].second = 1LL * pw[i - 1].second * p2 % mod2;
    }
    int ip1 = bin(p1, mod1 - 2, mod1);
    int ip2 = bin(p2, mod2 - 2, mod2);
    ipw[0] = {1, 1};
    for (int i = 1; i < N; i++) {
        ipw[i].first = 1LL * ipw[i - 1].first * ip1 % mod1;
        ipw[i].second = 1LL * ipw[i - 1].second * ip2 % mod2;
    }
}

pair<int,int>string_hash(string s)
{
    int n = s.size();
    pair<int,int>hs({0,0});
    for(int i = 0;i < n;i++)
    {
        hs.first += 1ll*s[i]*pw[i].first%mod1;
        hs.first %= mod1;
        hs.second += 1ll*s[i]*pw[i].second%mod2;
        hs.second %= mod2;
    }
    return hs;
}  

struct H {
    pair<int, int> prefix[N];
    void build(string &s) {
        for (int i = 0; i < (int) s.size(); i++) {
            prefix[i].first = 1LL * s[i] * pw[i].first % mod1;
            if (i)prefix[i].first = 1LL * (1LL * prefix[i].first + prefix[i - 1].first) % mod1;
            prefix[i].second = 1LL * s[i] * pw[i].second % mod2;
            if (i)prefix[i].second = 1LL * (1LL * prefix[i].second + prefix[i - 1].second) % mod2;
        }
    }
 
    pair<int, int> get_hash(int i, int j) {//i theke j substring er hashid return korbe
        pair<int, int> ans = {0, 0};
        ans.first = prefix[j].first;
        if (i) ans.first = 1LL * (1LL * (1LL * ans.first - prefix[i - 1].first) + mod1) % mod1;
        ans.first = 1LL * ans.first * ipw[i].first % mod1;
        ans.second = prefix[j].second;
        if (i) ans.second = 1LL * (1LL * (1LL * ans.second - prefix[i - 1].second) + mod2) % mod2;
        ans.second = 1LL * ans.second * ipw[i].second % mod2;
        return ans;
    }
}h1;


void solve()
{
    int n,k;
    cin>> n >> k;
    string s;
    cin >> s;
    s += s;
    h1.build(s);
    int m;
    cin>> m;
    map<pair<int,int>,int>mp;
    for(int i = 1;i <= m;i++)
    {
        string ss;
        cin>>ss;
        mp[string_hash(ss)] = i;
    }
    int t = n;
    n = s.size();
    for(int j = 0;j < k;j++)
    {
        vi ans;
        set<int>st;
        for(int i = j;i <= n-k;i += k)
        {
            if(mp.count(h1.get_hash(i,i+k-1)))
            {
                if(!st.count(mp[h1.get_hash(i,i+k-1)]))
                {
                    ans.pb(mp[h1.get_hash(i,i+k-1)]); 
                    st.insert(mp[h1.get_hash(i,i+k-1)]);
                }
                else
                    break;
            }
            else    
                break;
        }
        if(ans.size() == t)
        {
            cout << "YES" << endl;
            for(int i = 0;i < t;i++)
                cout << ans[i] << " ";
            return;
        }
    }
    cout << "NO" << endl;
}   

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // auto st = clock();
    precal();
    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    // cerr << 1.0*(clock()-st)/CLOCKS_PER_SEC << endl;
    return 0;
}
/*Problem_link
    https://codeforces.com/contest/1968/problem/G1 (snippet ei problem tar)
*/