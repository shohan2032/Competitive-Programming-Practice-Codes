#include <bits/stdc++.h>

using namespace std;

#define db long long
#define ll long long
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
 
void solve()
{
    ll n;
    cin >> n;
    ll x = (n*(n+1))/2;
    x--;
    ll need =n-(x % n);
    cout << need << " ";
    for(int i =2;i <= n;i++)
        cout << i << " ";
    cout << endl;
    
}   

int main()
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