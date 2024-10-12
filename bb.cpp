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
bool vis[N];
int dis[N];
queue<int>q;
int n,m;
void bfs(int u)
{
    q.push(u);
    vis[u] = true;
    if(u > 1){
        q.push(u-1);
        ad_list[u].pb(u-1);
        dis[u-1] = 1;
    }
    if(2*u <= 2*m){
        q.push(u*2);
        ad_list[2*u].pb(u*2);
        dis[u*2] = 1;
    }
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        if(u == m)
            break;
        fr(ad_list[u]){
            if(!vis[i]){
                cout << u << endl;
                vis[i] = 1;
                if(i > 1 and !vis[i-1])
                {
                    dis[u-1] = dis[u]+1;
                        // ad_list[i].pb(i-1);
                    q.push(u-1);
                        // vis[i-1] = 1;
                }
                if(2*u <= 2*m and !vis[u*2]){
                    dis[2*m] = dis[u]+1;
                        // ad_list[i].pb(2*m);
                    q.push(u*2);
                        // vis[i*2] = 1;
                }  
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