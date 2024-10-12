#include <bits/stdc++.h>

using namespace std;

#define db long long
#define ll long long
#define int ll
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
bool vis[N];
int target,cnt= 0;
set<char>check;
string s;
void dfs(int u)
{
    if(check.size()==target)
        return;
    cnt++;
    check.insert(s[u]);
    vis[u] = true;
    fr(ad_list[u]){
        if(!vis[i])
            dfs(i);
    }
}

void solve()
{
    int n;
    cin >> n >>s;
    set<char>st;
    map<char,vi>mp;
    int f = 1e18;
    char ch;
    for(int i = 0;i < n;i++)
    {
        st.insert(s[i]);
        mp[s[i]].pb(i);
    }
    fr(mp)
    {
        if(i.second.size() < f)
        {
            f = i.second.size();
            ch = i.first;
        }
    }
    cout << ch;
    target = st.size();
    for(int i = 0;i < n-1;i++)
    {
        ad_list[i].pb(i+1);
        ad_list[i+1].pb(i);
    }
    int ans = 1e18;
    fr(mp[ch])
    {
        dfs(i);
        ans = min(ans,cnt);
        cnt = 0;
        memset(vis,false,n+5);
        check.clear();
    }
    cout << ans << endl;
}   

int32_t main()
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