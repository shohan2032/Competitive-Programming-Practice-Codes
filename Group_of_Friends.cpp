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

int const N = 2e5+9;
int siz[N],parent[N];
int ans;
//overall TC of DSU is constant.O(alpha(N)) --> reversed ackerman function..It increase very slowly.That is almost N.
void make(int n)//add new node to our current sets
{
    parent[n] = n;
    siz[n] = 1;
}

int find(int n)//return the root of that set where the node n belonged to.
{
    if(parent[n] == n)
        return n;
    return parent[n] = find(parent[n]);
}

void uni(int a,int b)//set node a and b to the same group
{
    a = find(a);//a node er root ta finding
    b = find(b);//b node er root ta finding

    //path compression
    if(a != b)//when both a and b are not belonged to the same set
    {
        ans--;
        //union by size
        //We will add small tree to the big tree so that the depth of the tree will be smaller
        if(siz[a] < siz[b])
            swap(a,b);
        parent[b] = a;
        siz[a] += siz[b];
    }
}

void solve()
{

    int n;
    cin >> n;
    ans = n;
    for(int i = 1;i <= n;i++)
        make(i);
    int ma = 0;
    int track[100005] = {0};
    for(int i = 1;i <= n;i++)
    {
        int x;
        cin >> x;
        set<int>st;
        for(int j = 2;j*j <= x;j++)
        {
            if(x % j == 0)
            {
                st.insert(j);
                while(x % j == 0)
                    x /= j;
            }
        }
        if(x > 1)
            st.insert(x);
        
        for(auto &j:st)
        {
            if(track[j])
                uni(track[j],i);
            track[j] = i;
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
    // cin >> t;
    while (t--)
        solve();

    // cerr << 1.0*(clock()-st)/CLOCKS_PER_SEC << endl;
    return 0;
}
/*Problem_link

*/