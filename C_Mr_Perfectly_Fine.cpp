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


void solve()
{
    int n;
    cin >> n;
    vi o,t,b;
    while(n--)
    {
        ll x;
        string s;
        cin >> x >> s;
        if(s == "11")
            b.pb(x);
        else if(s[0] == '1')
            o.pb(x);
        else if(s[1] == '1')
            t.pb(x);
    }
    ll x = 0,y = 0;
    sort(all(o));
    sort(all(t));
    sort(all(b));
    if(!o.empty() and !t.empty())
        x = o[0]+t[0];
    if(!b.empty())
        y = b[0];
    if(x != 0 and y != 0)
        cout << min(x,y) << endl;
    else
    {
        if(x != 0 and y == 0)
            cout << x << endl;
        else if(x == 0 and y != 0)
            cout << y << endl;
        else
            cout << -1 << endl;
    }
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