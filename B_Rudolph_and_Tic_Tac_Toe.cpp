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
    char ch[4][4];
    for(int i = 1;i <= 3;i++)
    {
        for(int j = 1;j <= 3;j++)
            cin >> ch[i][j];
    }
    if(ch[1][1] == ch[2][2] and ch[1][1] == ch[3][3])
    {
        if(ch[1][1] != '.'){
            cout << ch[1][1] << endl;
            return;
        }
    }
    if(ch[3][1] == ch[2][2] and ch[3][1] == ch[1][3])
    {
        if(ch[3][1] != '.'){
            cout << ch[3][1] << endl;
            return;
        }
    }
    if(ch[1][2] == ch[2][2] and ch[1][2] == ch[3][2])
    {
        if(ch[1][2] != '.'){
            cout << ch[1][2] << endl;
            return;
        }
    }
    if(ch[1][1] == ch[1][2] and ch[1][1] == ch[1][3])
    {
        if(ch[1][1] != '.'){
            cout << ch[1][1] << endl;
            return;
        }
    }
    if(ch[1][3] == ch[2][3] and ch[1][3] == ch[3][3])
    {
        if(ch[1][3] != '.'){
            cout << ch[1][3] << endl;
            return;
        }
    }
    if(ch[1][1] == ch[2][1] and ch[1][1] == ch[3][1])
    {
        if(ch[1][1] != '.'){
            cout << ch[1][1] << endl;
            return;
        }
    }
    if(ch[2][1] == ch[2][2] and ch[2][1] == ch[2][3])
    {
        if(ch[2][1] != '.'){
            cout << ch[2][1] << endl;
            return;
        }
    }
    if(ch[3][1] == ch[3][2] and ch[3][1] == ch[3][3])
    {
        if(ch[3][1] != '.'){
            cout << ch[3][1] << endl;
            return;
        }
    }
    cout << "DRAW" << endl;
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