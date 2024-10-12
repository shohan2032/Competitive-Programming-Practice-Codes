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

#define dbg(args...) do {cerr << #args << " : "; arif(args); } while(0)
clock_t tStart = clock();
#define timeStamp dbg("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)
void arif () {cerr << endl;}
template <typename T>void arif( T a[], int n ) {for(int i = 0; i < n; ++i) cerr << a[i] << ' ';cerr << endl;}
template <typename T, typename ... hello>void arif( T arg, const hello &... rest) {cerr << arg << ' ';arif(rest...);}

void solve()
{
    int n,k;
    cin >> n >> k;
    vi vc(n);
    fr(vc)cin >> i;
    int f = vc[0],l = vc[n-1];
    dbg(f);
    int cnt = 0,i,ff = 0;
    for(i = 0;i < n;i++)
    {
        if(vc[i] == f)
            cnt++;
        if(cnt == k){
            ff = 1;
            break;
        }
    }
    if(ff)
    {
        if(f == l)
        {
            cout << "YES" << endl;
            return;
        }
        int cnt = 0;
        for(;i < n;i++)
        {
            if(vc[i] == l)
                cnt++;
        }
        if(cnt >= k)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
    else
        cout << "NO" << endl;
}   

int32_t main()
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