#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1000000007;

ll binmul(ll a, ll b, ll p)
{
    ll res = 0ll;
    while (b)
    {
        if (b & 1)
            res = (res + a) % p, b--;
        else
            a = (a + a) % p, b /= 2;
    }
    return res;
} //(a*b)%p

ll binpow(ll a, ll b, ll p)
{
    ll res = 1ll;
    while (b)
        {
        if (b & 1)
            res = binmul(res, a, p), b--;
        else
            a = binmul(a, a, p), b /= 2;
    }
    return res;
} //(a^b)%p

ll inverse(ll a, ll p)
{ 
    return binpow(a, p - 2, p); 
} //(a^-1)%p == (a^p-2)%p

void solve()
{
    ll n;
    cin >> n;
    ll y = n/2;
    ll ans1 = binmul(binmul(2*y,y+1,mod),(2*y)+1,mod);//2y*(y+1)*(2y+1) upper part of the first formula
    ans1 = binmul(ans1,inverse(3,mod),mod);//ans1 * 3^-1
    ll ans2 = binmul(n,n+1,mod);//n*(n+1) upper part of the 2nd formula
    ans2 = binmul(ans2,inverse(2,mod),mod);//ans2 * 2^-1
    cout << (ans1+ans2)%mod << endl;
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