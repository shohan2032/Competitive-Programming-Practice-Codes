#include <bits/stdc++.h>

using namespace std;

#define db long long
#define ll long long
#define int ll
#define vi vector<int>
#define vs vector<string>
#define vl vector<ll>
#define pii pair<int, int>
#define vpi vector<pair<int, int>>
#define vpl vector<pair<ll, ll>>
#define vpd vector<pair<double, double>>
#define vps vector<pair<string, string>>
#define mp(x, y) make_pair(x, y)
#define f first
#define s second
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
#define fr(cont) for (auto &i : (cont))
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.rbegin(), cont.rend()


void solve()
{
    int n,m,k;
    cin >> n >> m >> k;
    vpi vc;
    int x,y,f = 0;
    for(int i = 0;i <= k;i++)
    {
        int a,b;
        cin >> a >> b;
        if(i == 0)
        {
            x = a;
            y = b; 
        }
        else{
            vc.pb(mp(a,b));
            if(x == a and y == b)
                f = 1;
        }
    }
    //idea hocche emon kono cell exist kore?jeita te viky and tar jekono ekta fd er ashte same step dite hobe.jehetu same step a oi cell a asha jabe ar jehetu or step er upor depend kore or fd step dei so oi khete NO
    if(f)
    {
        cout << "NO" << endl;
        return;
    }
    fr(vc)
    {
        for(int k = 1;k <= n;k++)
        {
            for(int j = 1;j <= m;j++)
            {
                if((k != x or y != j) and (i.first != k or i.second != j))
                {
                    if(abs(i.first - k)+abs(i.second - j) == abs(x-k)+abs(y-j))
                    {
                        cout << "NO" << endl;
                        return;
                    }
                }
            }
        }
    }
    cout << "YES" << endl;
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