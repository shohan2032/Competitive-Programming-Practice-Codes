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
const ll mod = 1000000007;

ll ans[100000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(ans,-1,sizeof(ans));
    for(ll i = 1;i <= 1000;i++)
    {
        ll s = 0;
        for(int j = 1;j*j <= i;j++){
            if(i % j == 0)
            {
                s += j;
                if(i/j != j)
                    s += i/j;
            }
        }
        ans[s] = max(ans[s],i);
    }
    int n;
    int t = 1;
    while(cin >> n and n)
    {
        if(ans[n] != -1)
            cout << "Case " << t++ << ": " << ans[n] << endl;
        else
            cout << "Case " << t++ << ": " << -1 << endl;
    }
    
    return 0;
}
/*Problem_link

*/