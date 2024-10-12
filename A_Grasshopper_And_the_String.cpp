#include <bits/stdc++.h>

using namespace std;

#define db long long
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define fr(cont) for (auto &i : (cont))
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.rbegin(), cont.rend()

void solve()
{
    string s;
    cin >> s;
    vi ans;
    int cnt = 0;
    for(int i = 0;i < s.size();i++)
    {
        cnt++;
        if(s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U' or s[i] == 'Y')
        {
            ans.pb(cnt);
            cnt = 0;
        }
    }
    cnt++;
    ans.pb(cnt);
    cout << *max_element(all(ans)) << endl;
}   

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}