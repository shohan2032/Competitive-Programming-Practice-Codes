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

const int N = 9e5 + 9;
vi ad_list[N];
bool vis[N];
bool mark[N];

void dfs(int u)//TC-->BigO(v+e)
{
    vis[u] = true;
    fr(ad_list[u]){
        if(!vis[i])
            dfs(i);
    }
    if(!mark[u])
    {
        cout << u << " ";
        mark[u] = true;
    }
}

void solve()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        int x;
        cin >> x;
        while(x--)
        {
            int y;
            cin >> y;
            ad_list[i].pb(y);
        }
    }
    mark[1] = true;
    dfs(1);
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