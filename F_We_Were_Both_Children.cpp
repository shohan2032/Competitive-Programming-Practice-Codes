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
    int n;
    cin >> n;
    vi vc(n);
    ll ans[n+5],track[n+5];
    memset(ans,0,sizeof(ans));
    memset(track,0,sizeof(track));
    fr(vc){
        cin >>i;
        if(i <= n)
            track[i]++;
    }
    sort(all(vc));
    for(int i = 1;i <= n;i++)
    {
            for(int j = 1;j*j <= i;j++)
            {
                if(i % j == 0)
                {
                    if(track[j])
                        ans[i] += track[j];
                    if(j != i/j)
                    {
                        if(track[i/j])
                            ans[i] += track[i/j];
                    }
                }
            }
        
    }
    ll an = 0;
    for(int i = 1;i <= n;i++)
        an = max(an,ans[i]);
    cout << an << endl;
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