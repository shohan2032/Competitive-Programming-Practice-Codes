#include <bits/stdc++.h>

using namespace std;

#define db long long
#define ll long long
#define int ll
#define vi vector<int>
#define vs vector<string>
#define vl vector<int>
#define pi pair<int, int>
#define vpi vector<pair<int, int>>
#define vpl vector<pair<int, int>>
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
    cin>> n;
    vi v(n+5),l_r(n+5,0),r_l(n+5,0);
    for(int i = 1;i <= n;i++){
        cin>> v[i];
    }
    l_r[2] = 1;
    for(int i=2;i < n;i++)
    {
        int l_c = abs(v[i]-v[i-1]);
        int r_c = abs(v[i]-v[i+1]);
        if(r_c <= l_c)
            l_r[i+1] = l_r[i]+1;
        else
            l_r[i+1] = l_r[i]+r_c;
    }
    r_l[n-1] = 1;
    for(int i = n-1;i > 1;i--)
    {
        int l_c = abs(v[i]-v[i+1]);
        int r_c = abs(v[i]-v[i-1]);
        if(r_c <= l_c)
            r_l[i-1] = r_l[i]+1;
        else
            r_l[i-1] = r_l[i]+r_c;
    }
    // for(int i= 1;i <= n;i++)
    //     cout << l_r[i] << " " << r_l[i] << endl;
    int m;
    cin>> m;
    while(m--)
    {
        int x,y;
        cin >> x >>y;
        if(x < y)
            cout << l_r[y]-l_r[x] <<endl;
        else    
            cout << r_l[y]-r_l[x] << endl;
    }

    
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
    https://codeforces.com/problemset/problem/20/C (getting shortest path between 1 and n in a weighted graph)

    https://codeforces.com/contest/450/problem/D
*/