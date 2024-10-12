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
    string s,t;
    int n,m;
    cin >> n >> m >> s >> t;
    bool tgood = true,sgood = true;
    for(int i = 0;i < m-1;i++)
    {
        if(t[i] == t[i+1])
        {
            tgood = false;
            break;
        }
    }
    for(int i = 0;i < n-1;i++)
    {
        if(s[i] == s[i+1])
        {
            if(tgood)
            {
                if(t[0] == s[i] or t[m-1] == s[i])
                {
                    sgood = false;
                    break;
                }
            }
            else
                sgood= false;
        }
    }
    if(sgood)
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