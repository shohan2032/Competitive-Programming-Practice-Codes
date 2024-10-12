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
    cin>> n;
    vi vc(n);
    map<int,deque<int>>mp;
    for(int i= 0;i < n;i++)
    {
        cin>>vc[i];
        mp[vc[i]].pb(i);
    }
    int cnt = 0;
    fr(mp)
    {
        if(i.second.size() >= 2)
            cnt++;
    }
    int ans[n+5];
    if(cnt >= 2)
    {
        cnt = 2;
        fr(mp){
            if(cnt == 2 and i.second.size() >= 2)
            {
                cnt--;
                ans[i.second.front()] = 1;
                i.second.pop_front();
                while(!i.second.empty())
                {
                    ans[i.second.front()] = 2;
                    i.second.pop_front();
                }
            }
            else if(cnt == 1 and i.second.size() >= 2)
            {
                cnt--;
                ans[i.second.front()] = 1;
                i.second.pop_front();
                while(!i.second.empty())
                {
                    ans[i.second.front()] = 3;
                    i.second.pop_front();
                }
            }
            else
            {
                while(!i.second.empty())
                {
                    ans[i.second.front()] = 1;
                    i.second.pop_front();
                }
            }
        }
        for(int i= 0;i < n;i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    else
        cout << -1 << endl;
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