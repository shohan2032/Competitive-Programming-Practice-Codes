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
#define fr(cont) for (auto &i : (cont))
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.rbegin(), cont.rend()

void solve()
{
    int n;
    cin >> n;
    deque<int>dq;
    int f = 1;
    string s = "1";
    for(int i = 1;i <= n;i++)
    {
        int x;
        cin >> x;
        if(dq.empty())
            dq.pb(x);
        else
        {
            if(f)
            {
                if(x >= dq.back())
                {
                    s += '1';
                    dq.pb(x);
                }
                else
                {
                    if(x <= dq.front())
                    {
                        f = 0;
                        dq.pb(x);
                        s += '1';
                    }
                    else
                        s += '0';
                }
            }
            else
            {
                if(x >= dq.back() and x <= dq.front())
                {
                    s += '1';
                    dq.pb(x);
                }
                else
                    s += '0';
            }
        }
    }
    cout << s << endl;
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