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

const int N = 1e5 + 9;
vi ad_list[N];
int cntb[N],cntw[N];
char ch[N];
ll dfs(int u)//TC-->BigO(v+e).DFS is a recursive travers algorithm for greaph.
{
    int ans = 0;
    fr(ad_list[u]){
        ans += dfs(i);
        cntb[u] += cntb[i];
        cntw[u] += cntw[i];
    }
    if(ch[u] == 'B')
        cntb[u]++;
    else
        cntw[u]++;
    if(cntb[u] == cntw[u])
        ans++;
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    for(int i = 2;i <= n;i++)
    {
        int x;
        cin >> x;
        ad_list[x].pb(i);
    }
    for(int i = 1;i <= n;i++)
        cin >> ch[i];
    cout << dfs(1) << endl;
    for(int i = 1;i <= n;i++){
        ad_list[i].clear();
        cntb[i] = 0;
        cntw[i] = 0;
    }
}   

int main()
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