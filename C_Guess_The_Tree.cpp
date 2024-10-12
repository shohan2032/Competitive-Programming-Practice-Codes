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
#define mo(a, b) (((a) % (b)) + (b)) % (b)

void solve()
{
    int n ;
    cin >> n;
    set<pair<int,int>>st;
    for(int i = 2;i <= n;i++)
    {
        int a = 1;
        int b = i;
        while(1)
        {
            cout << "? " << a << " " << b << endl;
            int x;
            cin >> x;
            if(a==x or b==x)
            {
                st.insert(mp(min(x,b),max(x,b)));
                break;
            }
            else
                a = x;
        }
    }
    cout << "! ";
    fr(st)
        cout << i.first << " " << i.second << " ";
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
    for(int i = 1;i <= t;i++)
    {
        // cout << "Case " << i << ": ";
        solve();
    }

    // cerr << 1.0*(clock()-st)/CLOCKS_PER_SEC << endl;
    return 0;
}
/*Problem_link

*/