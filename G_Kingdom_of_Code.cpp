#include <bits/stdc++.h>

using namespace std;
#define db long long
#define ll long long
#define int ll
#define vi vector<int>
#define vs vector<string>
#define pi pair<int, int>
#define vpi vector<pair<int, int>>
#define vpd vector<pair<double, double>>
#define vps vector<pair<string, string>>
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
#define fr(cont) for (auto &i : (cont))
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.rbegin(), cont.rend()

const int INF = 1e18;

void solve()
{
    int n,q;
    cin >> n;

    map<int,int>mp;
    map<pair<int,int>,int>h_d;

    for(int i = 1;i <= n;i++)
    {
        int s;
        cin >> s;
        vi vc(s+5);
        for(int j = 0;j < s;j++)
        {
            cin>> vc[j];
            mp[vc[j]] = i;
        }

        int dis1[s+5][s+5];

        for(int j = 0;j < s;j++)
            for(int k = 0;k < s;k++)
                cin>> dis1[j][k];

        for(int k = 0;k < s;k++)
            for(int i = 0;i < s;i++)
                for(int j = 0;j < s;j++)
                    if(dis1[i][k] != INF and dis1[k][j] != INF)
                        dis1[i][j] = min(dis1[i][j],dis1[i][k]+dis1[k][j]);
        
        for(int j = 0;j < s;j++)
            for(int k = 0;k < s;k++)
                h_d[mp(vc[j],vc[k])] = dis1[j][k];
    }

    //island
    int island[n+5][n+5];
    for(int j = 1;j <= n;j++)
    {
        for(int k = 1;k <= n;k++)
        {
            int x;
            cin>>x;
            island[j][k] = x;
        }
    }

    for(int k = 1;k <= n;k++)
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                if(island[i][k] != INF and island[k][j] != INF)
                    island[i][j] = min(island[i][j],island[i][k]+island[k][j]);
    
    vi min_is(n+5,INF);
    for(int k = 1;k <= n;k++)
        for(int i = 1;i <= n;i++)
            if(k!=i)
                min_is[k] = min(min_is[k],island[k][i]);

    cin >> q;
    while(q--)
    {   
        int u,v;
        cin>> u >> v;
        int x = mp[u],y = mp[v];
        if(x == y)
            cout << min(min_is[x]*2 , h_d[mp(u,v)]) << endl;
        else
            cout << island[x][y] << endl;
    }
}   

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // auto st = clock();
    int t = 1;
    cin>> t;
    for(int i = 1;i <= t;i++)
    {
        cout<< "Case " << "#" << i << ":" << endl;
        solve();
    }
    // cerr << 1.0*(clock()-st)/CLOCKS_PER_SEC << endl;
    return 0;
}
/*Problem_link
        https://codeforces.com/problemset/problem/1213/G
        https://codeforces.com/contest/25/problem/D
    https://codeforces.com/contest/1559/problem/D1
    https://codeforces.com/contest/1559/problem/D2
     https://codeforces.com/problemset/problem/277/A
     https://codeforces.com/contest/977/problem/E
    https://codeforces.com/problemset/problem/1167/C
    https://codeforces.com/problemset/problem/1927/F eita te dsu diye undirected graph er cycle detection and cycle path ber kora hoyeche
    https://codeforces.com/contest/1263/problem/D
*/