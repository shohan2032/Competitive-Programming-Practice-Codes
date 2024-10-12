#include <bits/stdc++.h>

using namespace std;

#define db long long
#define ll long long
#define vi vector<int>
#define vs vector<string>
#define vl vector<ll>

#define fr(cont) for (auto &i : (cont))
#define all(cont) cont.begin(), cont.end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // auto st = clock();
    int t = 1;
    cin >> t;
    for(int i = 1;i <= t;i++)
    {
        int n,q;
        cin >> n >> q;
        vi vc(n);
        fr(vc) cin >> i;
        cout<< "Case " << i << ':' << endl;
        while(q--)
        {
            int l,r;
            cin >> l >>r;
            int x = lower_bound(all(vc),l)-vc.begin();
            int y = upper_bound(all(vc),r)-vc.begin();
            cout << y-x << endl;
        }
    }

    // cerr << 1.0*(clock()-st)/CLOCKS_PER_SEC << endl;
    return 0;
}
/*Problem_link

*/