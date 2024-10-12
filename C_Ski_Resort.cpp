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



void solve()
{
    ll n,k,q;
    cin>> n >> k >> q;
    vl vc(n),v;
    fr(vc) cin >> i;
    int cnt = 0;
    for(int i = 0;i < n;i++)
    {
        if(vc[i] <= q)
            cnt++;
        else if(cnt)
        {
            v.pb(cnt);
            cnt = 0;
        }
    }
    if(cnt)
        v.pb(cnt);                                                                                    
    // fr(v) cout << i << " ";
    ll ans = 0;
    for(int i = 0;i < v.size();i++)
    {
        if(v[i] >= k){
            ll y = abs(v[i]-k)+1;
            ans += (y*(y+1))/2;
        }
        
    }
    cout << ans << endl;
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