/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
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

const int N = 1e3 + 9, p1 = 137, p2 = 277, mod1 = 1e9 + 7, mod2 = 1e9 + 9;//p2 = 281
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
}h1,h2;
class Solution {
public:
    string longestPalindrome(string s) {
        precal();
        string ss = s;
        h1.build(s);
        reverse(all(s));
        h2.build(s);
        int n = s.size();
        int m = 0,mi = 0;
        for(int i = 0;i < n;i++)
        {
            for(int j = i,k = n-i-1;j < n;j++,k--)
            {
                int len = j-i+1;
                if(h1.get_hash(i,j) == h2.get_hash(k,k+len-1))
                {
                    if(len > m)
                    {
                        m = len;
                        mi = i;
                    }
                }
            }
        }
        return ss.substr(mi,m);
    }
};
// @lc code=end

