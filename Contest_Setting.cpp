#include <bits/stdc++.h>

using namespace std;

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

ll powss(ll a, ll p){if(p==0) return 1;if(p==1) return a;else if(p&1) {return a*powss(a*a,p/2);}else {return powss(a*a,p/2);}}


int n,y;
bool ok(int m)
{
    int r1 = m/2;
    int r2 = (m%2 == 0?m/2:m/2 + 1);
    int total = (r1*r1)+(r2*r2)+(m*y);
    if(total <= n)
        return true;
    else
        return false;
    
    
}
void solve()
{
    cin >> n>> y;
    int l = 0,r = 1;
    while(ok(r))
        r *= 2;
    while(l < r-1)
    {
        int m = (l+r)/2;
        if(ok(m))
            l = m;
        else    
            r = m;
    }
    cout << powss(2,l) << endl;
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