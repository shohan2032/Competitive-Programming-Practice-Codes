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

int const n = 4e6+9;
bool mark[n];
vl vc;
void s()
{
    mark[0] = mark[1] = 1;
    for(int i = 2;i < n;i++)
    {
        if(!mark[i])
        {
            vc.pb(i);
            for(int j = i+i;j < n;j += i)
                mark[j] = 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >>n;
    int arr[n+5] = {0};
    // cout << 2 << endl;
    for(int i = 2;i<=n+1;i++)
    {
        if(arr[i] == 0)
            arr[i] = 1;
        // cout << 1 << " ";
        if(arr[i] == 1){
            for(int j = i+i;j <= n+1;j += i)
                arr[j] = 2;
                // cout << 2 << " ";
        }
    }
    if(n <= 2)
        cout << 1 << endl;
    else
        cout << 2 << endl;
    for(int i =2;i<=n+1;i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
/*Problem_link

*/