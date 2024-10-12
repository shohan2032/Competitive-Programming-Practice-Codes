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

/*BS
    cin >> y;
    bool found = false;
    l = 0;
    r = n-1;
    while(l <= r)//(l < r - 1)
    {
      m = (l+r)/2;
      if(vc[m] == y)
      {
        found = true;
        break;
      }
      else if(y > vc[m])
      {
        l = m+1;//l = m
      }
      else
        r = m-1;//r = m
    }
    if(found)
      cout << "YES\n";
    else
      cout << "NO\n";
*/
/*LB__UB
    l = -1,r = n;
        while(l + 1 != r)
        {
            m = l+r/2;
            if(vc[m] >= x)///if(vc[m] > x) for upper bound
                r = m;
            else
                l = m;",
        }
        cout << r;
*/

bool cmp(const pair<string, int> &A, const pair<string, int> &B)
{
    if (A.first == B.first)
        return A.second > B.second;
    else
        return A.first < B.first;
}

  // set<int>st;
  // st.insert(1); st.insert(10);
  // auto it = st.begin();
  // int x = *it;
  // auto itt = st.end();
  // itt--;
  // int y = *itt;
  // cout<< x << " " << y << endl;
  
  // map<int,int>mp;
  // mp[1] = 1;
  // mp[2] = 2;
  // auto it = mp.begin();
  // int x = it->first;
  // auto itt = mp.end();
  // itt--;
  // int y = itt->first;
  // cout<< x << " " << y << endl;
void solve()
{
    int n;
    cin >> n;
    map<int,int>mp;
    for(int i =1;i <= n;i++)
    {
        int x;
        cin >>x;
        mp[x]++;
    }
    int q;
    cin >> q;
    while(q--)
    {
        //from the equations we can get Ai^2 - X*Ai + Y = 0 
        //same Aj^2 - X*Aj + Y = 0
        //comparing it to the equation of vieta's formula Ax^2 - Bx + C = 0 we can have here A = 1, x = Ai and Aj. B = X, C = Y;
        //Now we need determinant = B^2 - 4*A*C = X^2 - 4*1*Y;
        //we know that if determinant > 0 then the answer of root exist
        //if determinant = 0 then the both root are same
        //here root1 = (X + sqrt(X^2 - 4*1*Y))/2
        //here root2 = (X - sqrt(X^2 - 4*1*Y))/2
        //the the ans will be count of root1 * count of root2
        int x,y;
        cin >> x >> y;
        int determinant = (x*x) - (4*y);//b^2 - 4*a*c
        if(determinant > 0)
        {
            int a = sqrt(determinant);
            if(a*a == determinant)//sqrt(determinant) decimal value dile ans thakbe na cz tokhon root gulo decimal a ashbe,but amar targeted Ai and Aj hocche integer
            {
                if(((x+a)&1) or ((x-a)&1))//odd hole 2 diye vag korle decimal value ashbe.As Ai and Aj integer hote hobe so ans 0
                    cout << 0 << endl;
                else
                {
                    int r1 = (x+a)/2;
                    int r2 = (x-a)/2;
                    cout << mp[r1]*mp[r2] << " ";
                }
            }
            else
                cout << 0 << " ";
        }
        else if(determinant == 0)
        {
            if(x&1)//sqrt(determinant) = 0 so r1 and r2 same
                cout << 0 << endl;
            else
            {
                int r1 = x/2;
                int cnt = mp[r1];
                cout << (cnt*(cnt-1))/2 << " ";
            }
        }
        else 
            cout << 0 << " ";
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
    while (t--)
        solve();

    // cerr << 1.0*(clock()-st)/CLOCKS_PER_SEC << endl;
    return 0;
}
/*Problem_link

*/