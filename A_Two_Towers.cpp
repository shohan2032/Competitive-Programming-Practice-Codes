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
    int n,m;
    cin >> n >> m;
    string s1,s2;
    cin >> s1 >> s2;
    int f = 0;
    for(int i =0;i <n-1;i++)
    {
        if(s1[i] == s1[i+1]){
            f++;
            break;
        }

    }
    for(int i =0;i <m-1;i++)
    {
        if(s2[i] == s2[i+1]){
            f++;
            break;
        }

    }
    if(f == 0)
    {
        cout << "YES" << endl;
        return;
    }
    if(f == 2)
    {
        cout << "NO" << endl;
        return;
    }
    int cnt1 = 0,cnt2 = 0;
    for(int i =0;i <n-1;i++)
    {
        if(s1[i] == s1[i+1]){
            cnt1++;
        }
    }
    for(int i =0;i <m-1;i++)
    {
        if(s2[i] == s2[i+1]){
            cnt2++;
        }
    }
    if(cnt1 > 1 or cnt2 > 1 or s1.back() == s2.back())
    {
        cout << "NO" << endl;
    }
    else
        cout << "YES" << endl;
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