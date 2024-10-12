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
    int n,k,x;
    cin >> n >> k >> x;
    for(int i = 1;i <= k;i++)
    {
        if(i != x)
        {
            if(n % i == 0)  
            {
                int cnt = n/i;
                cout << "YES" <<  endl << cnt << endl;
                while(cnt--)
                    cout << i << " ";
                cout << endl;
                return;
            }
            else
            {
                if((n % i) != x)
                {
                    int cnt = n/i;
                    cout << "YES" <<  endl << cnt+1 << endl;
                    while(cnt--)
                        cout << i << " ";
                    cout << n%i << endl;
                    return;
                }
                else
                {
                    if(i+1 <= k)
                    {
                        int cnt = (n-1)/i;
                        cout << "YES" <<  endl << cnt << endl;
                        cnt--;
                        while(cnt--)
                            cout << i << " ";
                        cout << i+1 << endl;
                        return;
                    }
                }
            }
        }
    }
    cout << "NO" << endl;
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