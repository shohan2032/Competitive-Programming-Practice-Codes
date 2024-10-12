#include <bits/stdc++.h>

using namespace std;

#define db long long
#define ll long long
#define vl vector<ll>


#define fr(cont) for (auto &i : (cont))
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.rbegin(), cont.rend()
 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // auto st = clock();
    int t = 1;
    cin >> t;
    for(int i=1;i <= t;i++)
    {
        ll n,k;
        cin >> n >> k;
        vl vc(n);
        fr(vc) cin >> i;
        sort(all(vc));
        ll x = vc[n-1];
        partial_sum(all(vc),vc.begin());
        // cout << vc[n-1] << endl;
        x = x*(k-1);
        cout << "Case " << i << ": " << vc[n-1]+x << endl;
    }

    // cerr << 1.0*(clock()-st)/CLOCKS_PER_SEC << endl;
    return 0;
}
/*Problem_link

*/