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
priority_queue<int,vi,greater<int>> pq;
void dfs(int u)//TC-->BigO(v+e)
{
    cout << u << " ";
    vis[u] = true;
    fr(ad_list[u]){
        if(!vis[i])
            pq.push(i);
    }
    while(!pq.empty() and vis[pq.top()])
        pq.pop();
    if(!pq.empty())
        dfs(pq.top());
}

void solve()
{
    int v,e;
    cin>> v >> e;
    while(e--)
    {
        int u,v;
        cin >> u >> v;
        ad_list[u].pb(v);
        ad_list[v].pb(u); 
    }
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