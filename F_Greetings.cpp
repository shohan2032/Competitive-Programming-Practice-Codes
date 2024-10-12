#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

//ordered_set
template <typename DT>
using oset = tree<DT, null_type, less<DT>, rb_tree_tag, tree_order_statistics_node_update>;

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

bool cmp(const pair<int, int> &A, const pair<int, int> &B)
{
    return A.second < B.second;
}

void solve()
{
  /*
    1. Think Greedy
    2. Think Brute Force
    3. Think solution in reverse order
    4. Think DP [ check constraints carefully ]
    5. Check base cases for DP and prove solution for Greedy
    6. Think Graph
  */ 
    int n;
    cin>> n;
    vector<pair<int,int>>vc;
    vi l;
    for(int i= 1;i <= n;i++)
    {
        int x,y;
        cin>> x >> y;
        vc.pb(mp(x,y));
    }
    sort(all(vc),cmp);
    int ans = 0;
    oset <int>s;
    for(int i = 0;i < n;i++)
    {
        int x = vc[i].first;
        s.insert(x);
        ans += s.size()-(s.order_of_key(x)+1);
        // cout << x << " "<< p << " " << ans << endl;
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