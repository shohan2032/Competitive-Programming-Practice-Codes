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
    map<int,int>mp;
    for(int i= 1;i <= n;i++)
    {
        int x;
        cin>> x;
        mp[x]++;
    }
    if(mp.size() == 1)
        cout << "YES" << endl;
    else if(mp.size() == 2)
    {
        auto it = mp.begin();
        int x = it->second;
        auto itt = mp.end();
        itt--;
        int y = itt->second;
        if(n & 1 and abs(x-y) == 1)
            cout << "YES" << endl;
        else if(n % 2 == 0 and x == y)
            cout << "YES" << endl;
        else
            cout << "NO"  << endl;
    }
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