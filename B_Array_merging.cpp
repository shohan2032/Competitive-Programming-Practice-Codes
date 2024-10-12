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
    ll n;
    cin >> n;
    vl a(n),b(n);
    fr(a) cin >> i;
    fr(b) cin >> i;
    map<ll,ll>a1,b1;
    ll cnt = 1,check = a[0];
    for(int i = 1;i < n;i++)
    {
        if(a[i] != check)
        {
            a1[check] = max(cnt,a1[check]);
            cnt = 1;
            check = a[i];
        }
        else
            cnt++;
    }
    a1[a[n-1]] = max(cnt,a1[a[n-1]]);
    cnt = 1,check = b[0];
    for(int i = 1;i < n;i++)
    {
        if(b[i] != check)
        {
            b1[check] = max(cnt,b1[check]);
            cnt = 1;
            check = b[i];
        }
        else
            cnt++;
    }
    b1[b[n-1]] = max(cnt,b1[b[n-1]]);
    ll ans = 0;
    fr(a1)
        ans = max(ans,i.second + b1[i.first]);
    fr(b1)
        ans = max(ans,i.second + a1[i.first]);
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