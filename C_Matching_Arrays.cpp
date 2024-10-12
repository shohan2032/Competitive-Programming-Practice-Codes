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
    int n,x;
    cin>> n >> x;
    deque<int>a(n),b(n),ans(n+5);
    map<int,deque<int>>mp;
    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
        mp[a[i]].pb(i);
    }
    fr(b)
        cin>>i;
    sort(all(a));
    sort(all(b));
    for(int i = n-x,j = 0;i < n;i++,j++)
    {
        if(a[i] > b[j])
        {
            ans[mp[a[i]].front()] = b[j];
            mp[a[i]].pop_front();
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
    }
    for(int i = 0,j = x;i < n-x;i++,j++)
    {
        if(a[i] <= b[j])
        {
            ans[mp[a[i]].front()] = b[j];
            mp[a[i]].pop_front();
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    for(int i = 0;i < n;i++)
        cout << ans[i] << " ";
    cout << endl;
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