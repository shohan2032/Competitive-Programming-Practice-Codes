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
int c[N];
int p[N];
void dfs(int u,ll cnt)//TC-->BigO(v+e)
{
    vis[u] = true;
    c[u] += p[u]+cnt;
    fr(ad_list[u])
    {
        if(!vis[i])
            dfs(i,c[u]);
    }
}

void solve()
{
    int v,q;
    cin>> v >> q;
    int e = v-1;
    while(e--)
    {
        int u,v;
        cin >> u >> v;
        ad_list[u].pb(v);
    }
    int vc[v+5];
    for(int i = 1;i <= v;i++)
      cin>> vc[i];
    while(q--)
    {
      int x;
      cin >> x;
      p[x]++;
    }
    dfs(1,0);
    for(int i = 1;i <= v;i++)
    {
        c[i] = 0;
        p[i] = 0;
        vis[i] = 0;
        ad_list[i].clear();
        if(c[i] & 1)
            vc[i] = 1-vc[i];
        cout << vc[i] << " ";
    }
    cout << endl;
}   

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // auto st = clock();
    int t = 1;
    cin >> t;
    for(int i = 1;i <= t;i++)
    {
        cout << "Case " << i << ": ";
        solve();
    }

    // cerr << 1.0*(clock()-st)/CLOCKS_PER_SEC << endl;
    return 0;
}
/*Problem_link

*/