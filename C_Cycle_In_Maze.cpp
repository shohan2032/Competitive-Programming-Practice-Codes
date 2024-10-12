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


bool vis[100][100];
char arr[100][100];
int r,c,k,ii,jj;
string s;

void dfs(int i,int j)//TC-->BigO(v+e).DFS is a recursive travers algorithm for greaph.
{
    if(k){
        k--;
        if(i+1 <= r and arr[i+1][j] != '*')
            dfs(i+1,j),s += 'D';
        if(i-1 >= 1 and arr[i-1][j] != '*')
            dfs(i-1,j),s += 'U';
        if(j+1 <= c and arr[i][j+1] != '*')
            dfs(i,j+1),s += 'R';
        if(j-1 >= 1 and arr[i][j-1] != '*')
            dfs(i,j-1),s += 'L';
    }   
    else
        return;
    
}
void solve()
{
    cin >> r >> c >>k;
    int t = k;
    k /= 2;
    for(int i = 1;i <= r;i++)
    {
        for(int j = 1;j <= c;j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == 'X')
                ii = i,jj = j;
        }
    }
    if(t & 1)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    dfs(ii,jj);
    cout << s << endl;
}   

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // auto st = clock();
    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    // cerr << 1.0*(clock()-st)/CLOCKS_PER_SEC << endl;
    return 0;
}
/*Problem_link
    https://www.spoj.com/problems/DIGOKEYS/ bfs diye shortes path er problem
*/