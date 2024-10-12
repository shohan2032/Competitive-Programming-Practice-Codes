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


void solve()
{
    int n,k;
    cin>>n >>k;
    deque<int>dq(n);
    fr(dq) cin>>i;
    sort(all(dq));
    map<int,int>mp;
    ll ans = n+1,f = 1;
    for(int i = 0;i < n-1;i++)
    {
        if((abs(dq[i]-dq[i+1]) <= k))
            mp[f]++;
        else
        {
            mp[f]++;
            f++;
        }
    }
    mp[f]++;
    fr(mp)
    {
        int bad = n-i.second;
        ans = min(ans,bad);
    }
    cout << ans << endl;
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