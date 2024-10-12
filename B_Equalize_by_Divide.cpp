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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // auto st = clock();
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<double> vc(n);
        map<int,vi>mp;
        for(int i = 0;i < n;i++)
        {
            cin >> vc[i];
            mp[vc[i]].pb(i);
        }
        if(vc == vector<double>(n,vc[0]))
            cout << 0 << endl;
        else if(*min_element(all(vc)) == 1)
            cout << -1 << endl;
        else
        {
            vpi ans;
            while(mp.size() > 1)
            {
                auto it = mp.begin();
                int j = it->second.back();
                it++;
                int i = it->second.back();
                if(vc[i] == 2)continue;
                ans.pb(mp(i+1,j+1));
                mp[vc[i]].pop_back();
                if(mp[vc[i]].empty()) mp.erase(vc[i]);
                // vc[i] = (vc[i]+vc[j]-1)/vc[j];//we can calculate the rounded up(ceil) value like this equation
                vc[i] = ceil(vc[i]/vc[j]);
                mp[vc[i]].pb(i);
            }
            cout << ans.size() << endl;
            fr(ans)cout << i.first << " " << i.second << endl;
        }
    }

    // cerr << 1.0*(clock()-st)/CLOCKS_PER_SEC << endl;
    return 0;
}
/*Problem_link

*/