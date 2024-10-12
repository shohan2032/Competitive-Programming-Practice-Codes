#include <bits/stdc++.h>
 
using namespace std;

#define db long long
#define ll long long
#define vi vector<int>
#define vs vector<string>
#define vpi vector<pair<int, int>>
#define vpd vector<pair<double, double>>
#define vps vector<pair<string, string>>
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
#define fr(cont) for (auto &i : (cont))
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.rbegin(), cont.rend()
#define endl '\n'

 
const int N = 2e5 + 9, p1 = 137, p2 = 277, mod1 = 1e9 + 7, mod2 = 1e9 + 9;//p2 = 281
pair<int, int> pw[N], ipw[N], a[N];
 
int bin(int x, int y, int mod) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = 1LL * ans * x % mod;
        x = 1LL * x * x % mod;
        y >>= 1;
    }
    return ans;
}
 
 
void precal() {
    pw[0] = {1, 1};
    for (int i = 1; i < N; i++) {
        pw[i].first = 1LL * pw[i - 1].first * p1 % mod1;
        pw[i].second = 1LL * pw[i - 1].second * p2 % mod2;
    }
    int ip1 = bin(p1, mod1 - 2, mod1);
    int ip2 = bin(p2, mod2 - 2, mod2);
    ipw[0] = {1, 1};
    for (int i = 1; i < N; i++) {
        ipw[i].first = 1LL * ipw[i - 1].first * ip1 % mod1;
        ipw[i].second = 1LL * ipw[i - 1].second * ip2 % mod2;
    }
}
 
pair<int,int>string_hash(string s)
{
    int n = s.size();
    pair<int,int>hs({0,0});
    for(int i = 0;i < n;i++)
    {
        hs.first += 1ll*s[i]*pw[i].first%mod1;
        hs.first %= mod1;
        hs.second += 1ll*s[i]*pw[i].second%mod2;
        hs.second %= mod2;
    }
    return hs;
}  
 
struct H {
    pair<int, int> prefix[N];
    void build(string &s) {
        for (int i = 0; i < (int) s.size(); i++) {
            prefix[i].first = 1LL * s[i] * pw[i].first % mod1;
            if (i)prefix[i].first = 1LL * (1LL * prefix[i].first + prefix[i - 1].first) % mod1;
            prefix[i].second = 1LL * s[i] * pw[i].second % mod2;
            if (i)prefix[i].second = 1LL * (1LL * prefix[i].second + prefix[i - 1].second) % mod2;
        }
    }
 
    pair<int, int> get_hash(int i, int j) {//i theke j substring er hashid return korbe
        pair<int, int> ans = {0, 0};
        ans.first = prefix[j].first;
        if (i) ans.first = 1LL * (1LL * (1LL * ans.first - prefix[i - 1].first) + mod1) % mod1;
        ans.first = 1LL * ans.first * ipw[i].first % mod1;
        ans.second = prefix[j].second;
        if (i) ans.second = 1LL * (1LL * (1LL * ans.second - prefix[i - 1].second) + mod2) % mod2;
        ans.second = 1LL * ans.second * ipw[i].second % mod2;
        return ans;
    }
}h1;
 
int lcp(int i,int j,int x,int y)
{
    int l = 0,r = min(j-i+1,y-x+1)+1;
    while(l < r-1)
    {
        int m = l+r >> 1;
        if(h1.get_hash(i,i+m-1) == h1.get_hash(x,x+m-1))
            l = m;
        else
            r = m;
    }
    return l;
}
 
string s;
int compare(int i, int j, int x, int y) { // O(log n)
  int lc = lcp(i, j, x, y);
  int len1 = j - i + 1, len2 = y - x + 1;
  if (len1 == len2 and lc == len1) return 0; //equal
  else if (lc == len1) return -1;
  else if (lc == len2) return 1;
  else return (s[i + lc] < s[x + lc] ? -1 : 1);
  /*
    0 = equal
    -1 = first one is smaller
    1 = first one is larger
  */
}
 
 
void solve()
{
    cin>>s;
    int n = s.size();
    s += s;
    h1.build(s);
    int mi = 0,mj = n-1;
    for(int i = 1;i < n;i++)
    {
        int x = compare(mi,mj,i,i+n-1);
        if(x == 1)
            mi = i,mj = i+n-1;
    }
    cout << s.substr(mi,n) << endl;
}   
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // auto st = clock();
    precal();
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
 
    // cerr << 1.0*(clock()-st)/CLOCKS_PER_SEC << endl;
    return 0;
}
/*Problem_link
    https://codeforces.com/contest/1968/problem/G1 (snippet ei problem tar)
*/