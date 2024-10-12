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
    int n;
    cin >> n;
    vl vc(n);
    fr(vc) cin >> i;
    int j = n-1;
    ll gc;
    int f = 1;
    for(int i = 0;i < n/2;i++,j--)
    {
        if(vc[i] != vc[j] and f == 1){
            gc = abs(vc[i]-vc[j]);
            f = 0;
        }
        else if(vc[i] != vc[j])
            gc = __gcd(gc,abs(vc[i]-vc[j]));
    }
    if(f)
        cout << 0 << endl;
    else
        cout << gc << endl;
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