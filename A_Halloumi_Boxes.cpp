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
    int n,l;
    cin>> n >> l;
    vi v(n);
    fr(v) cin>>i;
    int c = 1;
    for(int i = 0;i < n-1;i++)
    {
        if(v[i] > v[i+1])
        {
            if(l == 1)
            {
                cout << "NO" << endl;
                return;
            }
        }
        else
        {
            if(c > l)
            {
                cout << "NO" << endl;
                return;
            }
            c = 0;
        }
    }
    if(c > l)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}   

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}