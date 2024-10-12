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
bool vis[N];
int dis[N];
queue<int>q;
int n,m;
void bfs(int u)
{
    q.push(u);
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        if(!vis[u]){
            vis[u] = 1;
            if(u > 1 and !vis[u-1])
            {
                dis[u-1] = dis[u]+1;
                q.push(u-1);
            }
            if(2*u <= 1e5 and !vis[u*2]){
                dis[2*u] = dis[u]+1;
                q.push(u*2);
            }  
        }
    }
}

void solve()
{
    cin >> n>> m;
    if(n >= m)
        cout << n-m << endl;
    else
    {
        bfs(n);
        cout << dis[m] << endl;
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
    https://www.spoj.com/problems/DIGOKEYS/ bfs diye shortes path er problem
*/