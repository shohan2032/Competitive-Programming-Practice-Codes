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
    cin>> n;
    int a = 1,b = 2;
    if(n-3 > 2)
    {
        int x = n-3;
        if(x % 3 != 0)
            cout << "YES" << endl << a << " " << b << " " << x << endl;
        else
        {
            if(x-2 > 0 and x-2 != 1 and x-2 != b+2)
                cout << "YES" << endl << a << " " << b+2 << " " << x-2 << endl;
            else
                cout << "NO" <<endl;
        }
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