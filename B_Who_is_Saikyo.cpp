#include <bits/stdc++.h>

using namespace std;

#define db long long
#define ll long long
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

//topshort fast -->TC(v+e)
const int N = 100;
int indeg[N];
vi ad_list[N];
bool vis[N];

void solve()
{
    int v,e;
    cin >> v >> e;
    while(e--)
    {
        int u,v;
        cin>> u >> v;//age u er kaj ,then v er kaj hobe.u --> v
        indeg[v]++;
        ad_list[u].pb(v);
    }
    vi ans,in_deg_zero;
    for(int i = 1;i <= v;i++)
    {
        if(indeg[i] == 0)
        {
            in_deg_zero.pb(i);
            // vis[i] = true;
        }
    }
    if(in_deg_zero.size() == 1)
        cout << in_deg_zero[0] << endl;
    else
        cout << -1 << endl;
}   

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // auto st = clock();
    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    // cerr << 1.0*(clock()-st)/CLOCKS_PER_SEC << endl;
    return 0;
}
/*Problem_link

*/