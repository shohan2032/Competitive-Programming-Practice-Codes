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
    int x,y,n;
    cin>> x >> y >> n;
    deque<int>ans;
    ans.pb(y);
    int i = 1;
    int cnt = n-2;
    while(cnt--)
    {
        y -= i;
        ans.push_front(y);
        i++;
    }
    ans.push_front(x);
    if(ans[0] < ans[1] and ans[1] - ans[0] >= i)
    {
        fr(ans)
            cout << i << " ";
        cout << endl;
    }
    else
        cout << -1 << endl;
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