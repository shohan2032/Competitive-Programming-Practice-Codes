#include <bits/stdc++.h>

using namespace std;

#define db long long
#define ll long long
#define int ll
#define vi vector<int>
#define vs vector<string>
#define vl vector<ll>
#define pii pair<int, int>
#define vpi vector<pair<int, int>>
#define vpl vector<pair<ll, ll>>
#define vpd vector<pair<double, double>>
#define vps vector<pair<string, string>>
#define mp(x, y) make_pair(x, y)
#define f first
#define s second
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

void solve()
{
    int n,m;
    cin>> n >> m;
    vi arr(m);
    int s = 0;
    for(int i = 0;i < m;i++){
        cin >> arr[i];
        s += arr[i];
    }
    int lagbe = n*(m-1);
    if(s <= lagbe)
        cout << 0 << endl;
    else
        cout << s-lagbe << endl;
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