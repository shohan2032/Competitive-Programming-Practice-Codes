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

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ca = 1;
    while(1)
    {
        int n;
        cin >> n;
        if(n == 0)
            break;
        map<string,int>mp;
        double cost[n+5][n+5];
        for(int i = 1;i<=n;i++)
        {
            string s;
            cin >> s;
            mp[s] = i;
        }
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= n;j++)
                cost[i][j] = 0.0;
        }
        int m;
        cin >> m;
        for(int i = 1;i <= m;i++){
            string u,v;
            double wt;
            cin >> u >> wt >> v;
            cost[mp[u]][mp[v]] = wt;
        }

        for(int k = 1;k <= n;k++)
        {
            for(int i = 1;i <= n;i++)
            {
                for(int j = 1;j <= n;j++)
                    cost[i][j] = max(cost[i][j],cost[i][k]*cost[k][j]);
            }
        }
        int f = 1;
        for(int i = 1;i <= n;i++)
        {
            if(cost[i][i] > 1.0){
                cout << "Case " << ca << ": Yes" << endl;
                f = 0;
                break;
            }
        }
        if(f)
            cout << "Case " << ca << ": No" << endl;
        ca++;
    }
    return 0;
}
/*Problem_link
        https://codeforces.com/problemset/problem/1213/G
        https://codeforces.com/contest/25/problem/C
*/