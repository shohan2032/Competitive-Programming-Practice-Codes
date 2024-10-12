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
bool vis[205][205];
char grid[205][205];
int n,m,total = 0;
ll dfs(int u,int v)//TC-->BigO(v+e)
{
    vis[u][v] = 1;
    int s = 1;
    if(v+1 <= m and grid[u][v+1] == '.')
    {
        total += dfs(u,v+1);
    }
    if(v+1 <= m and grid[u][v+1] == '.')
    {
        total += dfs(u,v+1);
    }
    if(v+1 <= m and grid[u][v+1] == '.')
    {
        total += dfs(u,v+1);
    }
    if(v+1 <= m and grid[u][v+1] == '.')
    {
        total += dfs(u,v+1);
    }
    return s;
}

void solve()
{
    
    cin >> n >> m;
    deque<pair<int,int>>dq;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            cin >> grid[i][j];
            if(grid[i][j] == '.')
                dq.pb(mp(i,j));
        }
    }
    ll ans = 0;
    while(!dq.empty())
    {
        int x = dq.front().first;
        int y = dq.front().second;
        if(!vis[x][y])
            ans = max(ans,dfs(x,y));
        dq.pop_front();
    }
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