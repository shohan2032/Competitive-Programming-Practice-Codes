#include <bits/stdc++.h>

using namespace std;


#define db long long
#define ll long long
#define int ll
#define vi vector<int>
#define vs vector<string>
#define vpi vector<pair<int, int>>
#define vpd vector<pair<double, double>>
#define vps vector<pair<string, string>>
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
#define fr(cont) for (auto &i : (cont))
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.rbegin(), cont.rend()


void solve()
{
    int n;
    string s;
    cin>> n >> s;
    int q;
    cin>> q;
    string l = s.substr(0,n);
    string r = s.substr(n,n);
    while(q--)
    {
        int t,a,b;
        cin >> t >> a >> b;
        a--;
        b--;
        if(t == 1){
            if(b <= n-1)
                swap(l[a],l[b]);
            else if(a > n-1)
                swap(r[a-n],r[b-n]);
            else{
                // cout << n << endl;
                swap(l[a],r[b-n]);
                // cout << l <<  "  " << r << endl;
            }
        }
        else{
            swap(l,r);
            // cout << l << " " << r << endl;
        }
    }
    cout << l << r << endl;
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