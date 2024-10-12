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

void solve()
{
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vi vc;
    for(int i = 0;i < n;i++)
    {
        if(s[i] == 'B')
            vc.pb(i+1);
    }
    if(!vc.empty())
    {
        int ans = 1;
        int cur = vc[0];
        for(int i = 1;i < vc.size();i++)
        {
            if(cur+k <= vc[i])
            {
                ans++;
                cur = vc[i];
            }
        }
        cout << ans << endl;
    }
    else
        cout << 0 << endl;
    
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