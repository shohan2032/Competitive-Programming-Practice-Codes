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

const int N = 2005;
bool vis[N][N];

char ch[N][N];
int r,c;
int ans[N][N];
void dfs(int x,int y,char c)
{
    if(ch[x][y] == c)
        ans[x][y] = 1;
    vis[x][y] = 1;
    if(y+1 <= c and !vis[x][y+1])
        dfs(x,y+1,ch[x][y]);
    if(x+1 <= r and !vis[x+1][y])
        dfs(x+1,y,ch[x][y]);
}

void solve()
{
    cin >> r >> c;
    for(int i = 1;i <= r;i++)
    {
        for(int j = 1;j <= c;j++)
        {
            cin >> ch[i][j];
        }
    }
    dfs(1,1,ch[1][1]);
    int an =0;
    for(int i = 1;i <= r;i++)
    {
        for(int j = 1;j <= c;j++)
        {
            if(!ans[i][j])
                an++;
        }
    }
    cout << an << endl;
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