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
    int r,c;
    cin >> r >> c;
    vi vc(r*c);
    fr(vc) cin >> i;
    ll ans = -MXL;
    sort(all(vc));
        //min ta ke 1,1 cell a boshiye
        ll x = vc[vc.size()-1];
        ll y = vc[vc.size()-2];
        int mi = vc[0];
        ll dif1 = x-mi;//max dif
        ll dif2 = y-mi;//2nd max dis
        if(r >= c)
        {
            ll cnt = ((r*c)-1)-(c-1);
            ll cntt = c-1;
            ans = max(ans,(dif1*cnt)+(dif2*cntt));
        }
        else
        {
            ll cnt = ((r*c)-1)-(r-1);
            ll cntt = r-1;
            ans = max(ans,(dif1*cnt)+(dif2*cntt));
        }

        //max ta 1,1 cell a boshiye
        sort(rall(vc));
        x = vc[vc.size()-1];//min 1
        y = vc[vc.size()-2];//min 2
        ll ma = vc[0];//max
        dif1 = ma-x;
        dif2 = ma-y;
        if(r >= c)
        {
            int cnt = ((r*c)-1)-(c-1);
            int cntt = c-1;
            ans = max(ans,(dif1*cnt)+(dif2*cntt));
        }
        else
        {
            int cnt = ((r*c)-1)-(r-1);
            int cntt = r-1;
            ans = max(ans,(dif1*cnt)+(dif2*cntt));
        }
        cout << ans << endl;
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