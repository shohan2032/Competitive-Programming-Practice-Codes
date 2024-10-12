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
    int n;
    cin >> n;
    deque<int> vc(2*n);
    fr(vc) cin >>  i;
    sort(all(vc));
    int s = 0;
    vpi ans;
    while(!vc.empty())
    {
        ans.pb(mp(vc.front(),vc.back()));
        vc.pop_back();
        vc.pop_front();
    }
    for(int i = 0;i < n-1;i++)
        s += abs(ans[i].first - ans[i+1].first) + abs(ans[i].second - ans[i+1].second);
    cout << s << endl;
    fr(ans)
        cout << i.first << " " << i.second << endl;
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