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
        ll a,b,c,k;
        cin >> a >> b >> c >> k;
        if(a == b and a == c)
        {
            cout << "Case " << i << ": Peaceful" << endl;
                continue;
        }
        vl vc;
        vc.pb(a);
        vc.pb(b);
        vc.pb(c);
        sort(all(vc));
        if(vc[0] >= k)
        {
            ll x = vc[0]-k;
            ll y = vc[1]-x;
            vl v;
            v.pb(x);
            v.pb(y);
            v.pb(vc[2]);
            v.sort(all(v));
            int x = unique(all(v))-v.begin();
            if(x == 2){
                cout << "Case " << i << ": Peaceful" << endl;
                continue;
            }

            x = vc[0]-k;
            y = vc[2]-x;
            vl v;
            v.pb(x);
            v.pb(y);
            v.pb(vc[1]);
            v.sort(all(v));
            x = unique(all(v))-v.begin();
            if(x == 2){
                cout << "Case " << i << ": Peaceful" << endl;
                continue;
            }

            x = vc[1]-k;
            y = vc[2]-x;
            vl v;
            v.pb(x);
            v.pb(y);
            v.pb(vc[0]);
            v.sort(all(v));
            x = unique(all(v))-v.begin();
            if(x == 2){
                cout << "Case " << i << ": Peaceful" << endl;
                continue;
            }

            cout << "Case " << i << ": Fight" << endl;
        }
        else if(vc[1] >= k)
        {
            ll x = vc[1]-k;
            ll y = vc[2]-x;
            vl v;
            v.pb(x);
            v.pb(y);
            v.pb(vc[0]);
            v.sort(all(v));
            x = unique(all(v))-v.begin();
            if(x == 2){
                cout << "Case " << i << ": Peaceful" << endl;

            }
            else
                cout << "Case " << i << ": Fight" << endl;
        }
        else
            cout << "Case " << i << ": Fight" << endl;
    }

    // cerr << 1.0*(clock()-st)/CLOCKS_PER_SEC << endl;
    return 0;
}
/*Problem_link

*/