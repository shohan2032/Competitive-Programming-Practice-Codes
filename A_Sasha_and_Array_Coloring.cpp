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
    deque<int>dq(n);
    fr(dq) cin >> i;
    sort(all(dq));
    ll ans = 0;
    if(n % 2 == 0)
    {
        while(!dq.empty())
        {
            ans += dq.back()-dq.front();
            dq.pop_back();
            dq.pop_front();
        }
    }
    else
    {
        while(dq.size() >= 3)
        {
            ans += dq.back()-dq.front();
            dq.pop_back();
            dq.pop_front();
        }
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