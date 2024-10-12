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

const int N = 2e5 + 9;
vi ad_list[N];
int depth[N];

double dfs(int u,ll p)//TC-->BigO(v+e)
{
    double s = 0;
    int cnt = 0;
    // depth[u] = depth[p]+1;
    fr(ad_list[u]){
        if(i != p)//this line can be deleted if we delete the 47th line also
        {
           s += 1 + dfs(i,u);
           cnt++;
        }
    }
    // cout << u << " " << s << endl;
    return (cnt?s/cnt:0);
}

void solve()
{
    int v,e;
    cin>> v;
    e = v-1;
    while(e--)
    {
        int u,v;
        cin >> u >> v;
        ad_list[u].pb(v);
        ad_list[v].pb(u);//this line can be deleted if we delete the 32th line also
    }
    cout << fixed << setprecision(15) << dfs(1,0) << endl;
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