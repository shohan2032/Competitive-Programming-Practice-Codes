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
    vi an;
    int a[n+5][n+5];
    for(int i = 0;i < n;i++)
    {
        int ans;
        int f = 1;
        for(int j = 0;j < n;j++)
        {
            int x;
            cin>>x;
            a[i][j] = x;
            if(i == j)
                continue;
            if(f){
                ans = x;
                f = 0;
            }
            else
                ans &= x;
        }
        an.pb(ans);
    }
    if(n == 1)//1 er jonno
    {
        cout << "YES" << endl;
        cout << 7 << endl;
        return;
    }
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++){
            if(i == j)
                continue;
            int x = (an[i]|an[j]);
            if(x != a[i][j])//i er sathe j 
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    fr(an)
        cout << i << " ";
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