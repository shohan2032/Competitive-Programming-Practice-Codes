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
    vi vc(n),v;
    fr(vc)
    {
        cin >> i;
        v.pb(abs(i));
    }
    ll cnt = 0;
    vl ans;
    for(int i = 0;i < n;i++)
    {
        if(vc[i] < 0)
            cnt++;
        else if(vc[i] == 0)
        {
            if(cnt != 0)
                cnt++;
        }
        else
        {
            if(cnt)
            {
                ans.pb(cnt);
                cnt = 0;
            }
        }
    }
    if(cnt)
        ans.pb(cnt);
    cout << accumulate(all(v),0ll) << " " << ans.size() << endl;
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