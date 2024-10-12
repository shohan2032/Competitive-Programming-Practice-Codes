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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long get_random(){
    return (long long)(rng());
}

long long get_random_in_range(long long L, long long R)
{
    long long rndm = get_random();
    return L + (rndm % (R - L + 1));
}

void solve()
{
    ll x, y;
    int a = 1000;
    int cnt = 0;
    while(a)
    {
        x = get_random_in_range(0, 1e7);
        y = get_random_in_range(0, 1e7);

        if(x > y && (x+y)%2 == 0)
        {
            ll b = (x+y)/2;
            ll c = (x-y)/2;
            if(__gcd(b,c) == 1)
                continue;
            cout << x << ' ' << y << endl;
            // break;
            a--;
            cnt++;
        }
    }
    cout << cnt << endl;
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