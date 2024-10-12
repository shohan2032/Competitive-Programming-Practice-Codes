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
bool cmp(const pair<ll, ll> &A, const pair<ll, ll> &B)
{
    if (A.first == B.first)
        return A.second < B.second;
    else
        return A.first > B.first;
}

void solve()
{
    int n,m,h;
    cin >> n >> m >> h;
    ll rp,rs;
    vpl vc;
    for(int i = 1;i <=n;i++)
    {
        vl v;
        v.pb(0);
        for(int j = 1;j <= m;j++)
        {
            int x;
            cin >> x;
            v.pb(x);
        }
        sort(all(v));
        partial_sum(all(v),v.begin());
        ll point = 0,penalty = 0;
        for(int j = 1;j <= m;j++)
        {
            if(v[j] <= h)
            {
                point++;
                penalty += v[j];
            }
        }
        vc.pb(mp(point,penalty));
        if(i == 1)
        {
            rs = point;
            rp = penalty;
        }
    }
    sort(all(vc),cmp);
    for(int i = 0;i < n;i++)
    {
        if(vc[i].first == rs and vc[i].second == rp)
        {
            cout << i+1 << endl;
            return;
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
    while (t--)
        solve();

    // cerr << 1.0*(clock()-st)/CLOCKS_PER_SEC << endl;
    return 0;
}
/*Problem_link

*/