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

// constants...
const double pi = acos(-1);
const ll mod = 1000000007;//998244353
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
string big_add(string a,string b){string ans;if(a.size() > b.size()){while(b.size() != a.size())b = '0'+b;}else{while(a.size() != b.size())a = '0'+a;}int carry = 0;for(int i = a.size()-1;i >= 0;i--){int x = a[i]-'0';int y = b[i]-'0';int sum = x+y+carry;if(sum >= 10){carry = 1;sum %= 10;}else carry = 0;ans += sum+'0';}if(carry)ans += '1';reverse(all(ans));return ans;}
string big_sub(string a,string b){string ans;if(a.size() > b.size()){while(b.size() != a.size())b = '0'+b;}else{while(a.size() != b.size())a = '0'+a;}int carry = 0;for(int i = a.size()-1;i >= 0;i--){int x = a[i]-'0';int y = b[i]-'0';if(carry)y++;int f = 0;if(x < y){x += 10;f = 1;}int sub = x-y;//x theke y biyog(a string theke b string biyog)
ans += sub+'0';if(f)carry = 1;else carry = 0;}while(ans.back() == '0')ans.pop_back();reverse(all(ans));return ans;}
int charToint(char ch){return ch-'0';}
char intTochar(int n){return 48+n;/*return '0'+n;*/}
//x theke d distance poriman clockwise agabe,n hocche total cell
int c_w(int x,int d,int n){x += d;x %= n;if(!x)x = n;return x;}
//x theke d distance poriman counter-clockwise pichabe,n hocche total cell
int cc_w(int x,int d,int n){x = (((x-d)%n)+n)%n;if(!x)x = n;return x;}

bool cmp(const pair<string, int> &A, const pair<string, int> &B)
{
    if (A.first == B.first)
        return A.second > B.second;
    else
        return A.first < B.first;
}
/*
    set<int>st;
    st.insert(1); st.insert(10);
    auto it = st.begin();
    int x = *it;
    auto itt = st.end();
    itt--;
    int y = *itt;
    cout<< x << " " << y << endl;
    
    auto it = st.lower_bound(val);
    it--;
    int x = *it;
    
    map<int,int>mp;
    mp[1] = 1;
    mp[2] = 2;
    auto it = mp.begin();
    int x = it->first;
    auto itt = mp.end();
    itt--;
    int y = itt->first;
    cout<< x << " " << y << endl;

    // must include this(instead of unordered_map use gp_hash_table)
    #include<ext/pb_ds/assoc_container.hpp>
    #include<ext/pb_ds/tree_policy.hpp>
    using namespace __gnu_pbds;
    using namespace std;

    gp_hash_table<int, int> mp;


    sort(a+1,a+n+1);array 1 index based sorting
    sort(a,a+n);array 0 index based sorting
    
    bs--> l < r-1(l = m or r = m) or l <= r(l = m+1 or r = m+1)
*/
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
    int n,q;
    cin>> n >> q;
    vector<string>vc(n+5);
    vi bg,br,by,gr,gy,ry;
    for(int i = 1;i <= n;i++)
    {
        cin>>vc[i];
        if(vc[i] == "BG")
            bg.pb(i);
        else if(vc[i] == "BR")
            br.pb(i);
        else if(vc[i] == "BY")
            by.pb(i);
        else if(vc[i] == "GR")
            gr.pb(i);
        else if(vc[i] == "GY")
            gy.pb(i);
        else if(vc[i] == "RY")
            ry.pb(i);
    }
    while(q--)
    {
        int x,y;
        cin>>x >> y;
        if(vc[x][0]==vc[y][0] or vc[x][0] == vc[y][1] or vc[x][1]==vc[y][0] or vc[x][1] == vc[y][1])
            cout << abs(x-y) << endl;
        else
        {
            int ans = 1e18;
            //common node of x and y which has color BG
            if(vc[x] != "BG" and vc[y] != "BG")
            {
                int ind = lower_bound(all(bg),x)-bg.begin();
                //right z
                if(ind < bg.size())
                {
                    int z = bg[ind];
                    ans = min(ans,abs(x-z)+abs(y-z));
                }
                //left z
                if(ind > 0)
                {
                    int z = bg[ind-1];
                    ans = min(ans,abs(x-z)+abs(y-z));
                }
            }
            //common node of x and y which has color BR
            if(vc[x] != "BR" and vc[y] != "BR")
            {
                int ind = lower_bound(all(br),x)-br.begin();
                //right z
                if(ind < br.size())
                {
                    int z = br[ind];
                    ans = min(ans,abs(x-z)+abs(y-z));
                }
                //left z
                if(ind > 0)
                {
                    int z = br[ind-1];
                    ans = min(ans,abs(x-z)+abs(y-z));
                }
            }
            //common node of x and y which has color BY
            if(vc[x] != "BY" and vc[y] != "BY")
            {
                int ind = lower_bound(all(by),x)-by.begin();
                //right z
                if(ind < by.size())
                {
                    int z = by[ind];
                    ans = min(ans,abs(x-z)+abs(y-z));
                }
                //left z
                if(ind > 0)
                {
                    int z = by[ind-1];
                    ans = min(ans,abs(x-z)+abs(y-z));
                }
            }
            //common node of x and y which has color GR
            if(vc[x] != "GR" and vc[y] != "GR")
            {
                int ind = lower_bound(all(gr),x)-gr.begin();
                //right z
                if(ind < gr.size())
                {
                    int z = gr[ind];
                    ans = min(ans,abs(x-z)+abs(y-z));
                }
                //left z
                if(ind > 0)
                {
                    int z = gr[ind-1];
                    ans = min(ans,abs(x-z)+abs(y-z));
                }
            }
            //common node of x and y which has color GY
            if(vc[x] != "GY" and vc[y] != "GY")
            {
                int ind = lower_bound(all(gy),x)-gy.begin();
                //right z
                if(ind < gy.size())
                {
                    int z = gy[ind];
                    ans = min(ans,abs(x-z)+abs(y-z));
                }
                //left z
                if(ind > 0)
                {
                    int z = gy[ind-1];
                    ans = min(ans,abs(x-z)+abs(y-z));
                }
            }
            //common node of x and y which has color RY
            if(vc[x] != "RY" and vc[y] != "RY")
            {
                int ind = lower_bound(all(ry),x)-ry.begin();
                //right z
                if(ind < ry.size())
                {
                    int z = ry[ind];
                    ans = min(ans,abs(x-z)+abs(y-z));
                }
                //left z
                if(ind > 0)
                {
                    int z = ry[ind-1];
                    ans = min(ans,abs(x-z)+abs(y-z));
                }
            }
            if(ans == 1e18)
                cout << -1 << endl;
            else
                cout << ans << endl;
        }
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
    for(int i = 1;i <= t;i++)
    {
        // cout << "Case " << i << ": ";
        solve();
    }

    // cerr << 1.0*(clock()-st)/CLOCKS_PER_SEC << endl;
    return 0;
}
/*Problem_link

*/