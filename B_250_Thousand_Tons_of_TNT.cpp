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

int ok(int p,int t,deque<int> v)
{
    deque<int>dq;
    for(int i = 1;i <= t/p;i++)
    {
        int x = p;
        int s = 0;
        while(x--)
        {
            s += v.front();
            v.pop_front();
        }
        dq.pb(s);
    }
    sort(all(dq));
    
    return abs(dq.front() - dq.back());
}
void solve()
{
    int n;
    cin>> n;
    deque<int> vc(n);
    fr(vc) cin>>i;
    int ans = 0;
    for(int i = 1;i*i <= n;i++)
    {
        if(n % i == 0){
            ans = max(ans,ok(i,n,vc));
            if(n/i != i)
                ans = max(ans,ok(n/i,n,vc));
        }
    }
    cout << ans << endl;
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