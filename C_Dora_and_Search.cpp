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
#define loop1 for (i = 0; i < n; i++)
#define loop2 for (j = 0; j < n; j++)
#define fr(cont) for (auto &i : (cont))
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.rbegin(), cont.rend()
#define inv a, b, i, j, k, l, r, t, q, cnt1 = 0, cnt2 = 0, x, y, z, n, cnt = 0, ma = INT_MIN, mi = INT_MAX, sum = 0
#define sv s1, s, s2, s3, s4
#define sv s1, s, s2, s3, s4
 
void solve()
{
    ll n;
    cin >> n;
    vl vc(n);
    map<ll,ll>mp;
    fr(vc)
    {
        cin >>i;
        mp[i]++;
    }
    int  l =0,r=n-1;
    // auto it1 = mp.begin();
    //     auto it2 = --mp.end();
    //     cout << it1->first << " " << it2->first << endl;
    while(l < r)
    {
        auto it1=mp.begin();
        auto it2=--mp.end();
        ll x = it1->first;
        ll y = it2->first;
        int  f = 1;
        if(vc[l] == x or vc[l] == y)
        {
            mp.erase(vc[l]);
            l++;
            f = 0;
        }
        if(vc[r] == x or vc[r] == y)
        {
            mp.erase(vc[r]);
            r--;
            f = 0;
        }
        if(f)
        {
            cout << l+1 << " "  << r+1 << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // auto st = clock();
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    // cerr << 1.0*(clock()-st)/CLOCKS_PER_SEC << endl;
    return 0;
}
/*Problem_link

*/