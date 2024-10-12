#include <bits/stdc++.h>

using namespace std;

#define db long long
#define ll long long
#define vl vector<ll>


#define fr(cont) for (auto &i : (cont))
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.rbegin(), cont.rend()

void solve()
{
    int n;
    cin >> n;
    vector<ll>mp(n+5),v(n+5);
    vector<ll> pe(n+5,0);
    map<ll,set<ll>>st;
    // vector<ll>v(n+10);
    for(int i = 1;i <= n;i++)
    {
        int x;
        cin >> x;
        mp[i] = x;
        pe[i]++;
        v[i] = i;
        st[i].insert(i);
    }
    int q;
    cin >> q;
    while(q--)
    {
        ll t;
        cin >> t;
        if(t == 1)
        {
            ll x,y;
            cin >> x >> y;
            if(mp[x] == 0 or mp[y] == 0)
                continue;
            if(mp[x] > mp[y])
            {
                fr(st[y]){
                    st[x].insert(i);
                    v[i] = x;
                }
                pe[x] += pe[y];
                pe[y]=0;
                v[y]=x;
                mp[x] += mp[y];
                mp[y] = 0;
            }
            else if(mp[x] < mp[y])
            {
                fr(st[x]){
                    st[y].insert(i);
                    v[i] = y;
                }
                pe[y] += pe[x];
                pe[x]=0;
                v[x]=y;
                mp[y] += mp[x];
                mp[x] = 0;
            }
        }
        else if(t == 2)
        {
            ll x;
            cin >>x;
            cout << pe[x] << endl;
        }
        else 
        {
            ll x;
            cin >> x;
            // if(mp[x] != 0)
            //     cout << x << endl;
            // else
                cout << v[x] << endl;
        }
    }
    // fr(st[4])
    //     cout << i << " ";
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