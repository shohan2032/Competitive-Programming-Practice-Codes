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

bool cmp(const pair<int, int> &A, const pair<int, int> &B)
{
    if (A.first == B.first)
        return A.second < B.second;
    else
        return A.first > B.first;
}

void solve()
{
    int n,k;
    cin >> n >> k;
    vpi vc;
    for(int i = 1;i <= n;i++)
    {
        int x;
        cin >> x;
        if(x >= k)
        {
            if(x % k == 0)
            {
                vc.pb(mp(k,i));
            }
            else
            {
                x %= k;
                vc.pb(mp(x,i));
            }
        }
        else
            vc.pb(mp(x,i));
    }
    sort(all(vc),cmp);
    for(int i = 0;i < n;i++){
        // cout << vc[i].first << " " << vc[i].second << endl;
        cout << vc[i].second << " ";
    }
    cout << endl;
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