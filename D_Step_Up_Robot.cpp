#include <bits/stdc++.h>

using namespace std;

#define db long long
#define ll long long
#define vi vector<int>
#define vs vector<string>
#define vl vector<ll>
#define pii pair<int,int>
#define vpi vector < pair <int,int> >

#define fr(cont) for(auto &i : (cont))

void solve()
{
    int n;
    cin >> n;
    vi s(n);
    fr(s) cin >> i;
    int m;
    cin >> m;
    set<int>trap;
    for(int i = 0;i < m;i++)
    {
        int y;
        cin >> y;
        trap.insert(y);
    }
    int x;
    cin >> x;
    int dp[x+5];
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(int i = 1;i <= x;i++)//i is the step where robot can go
    {
        if(!trap.count(i))//checking the trap steps
        {
            for(int j = 0;j < n;j++)//every s[j] step robot has a posibility to go to ith step 
            {
                if(i >= s[j])
                    dp[i] |= dp[i-s[j]];
            }
        }
    }
    if(dp[x] == 1)
        cout << "Yes" << endl;
    else        
        cout << "No" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //auto st = clock();
     int t = 1;
     ///cin >> t;
     while(t--)
         solve();

    //cerr << 1.0*(clock()-st)/CLOCKS_PER_SEC << endl;
    return 0;
}
/*Problem_link

*/