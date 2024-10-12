#include <bits/stdc++.h>

using namespace std;

#define db long long
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define fr(cont) for (auto &i : (cont))
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.rbegin(), cont.rend()

void solve()
{
    ll a,b;
    cin >> a >> b;
    if(a+1 == b)
    {
        cout << b%10 << endl;
        return;
    }
    ll n = 1;
    for(ll i = a+1;i <= b;i++)
    {
        if(i % 5ll == 0)
        {
            cout << 0 << endl;
            return;
        }
        n *= i%10;
    }
    cout << n%10ll << endl;
}   

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}