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
    vi vc(n);
    map<int,int>mp;
    fr(vc){
        cin >> i;
        mp[i]++;
    }
    vpi v;
    fr(mp)
    {
        v.pb(mp(i.first,i.second));
    }
    sort(rall(v));
    v.pb(mp(0,0));
    map<int,int>m;
    int cur = v[0].second;
    for(int i = 0;i < v.size()-1;i++)
    {
        m[cur] = v[i].first - v[i+1].first;
        cur += v[i+1].second;
    }
    if(mp==m)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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