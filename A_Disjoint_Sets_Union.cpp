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

int const N = 1e5+9;
int siz[N],parent[N],ma[N],mi[N];

//overall TC of DSU is constant.O(alpha(N)) --> reversed ackerman function..It increase very slowly.That is almost N.
void make(int n)//add new node to our current sets
{
    parent[n] = n;
    siz[n] = 1;
    ma[n] = n;
    mi[n] = n;
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
        //union by size
        //We will add small tree to the big tree so that the depth of the tree will be smaller
        if(siz[a] < siz[b])
            swap(a,b);
        ma[a] = max(ma[a],ma[b]);
        mi[a] = min(mi[a],mi[b]);
        parent[b] = a;
        siz[a] += siz[b];
    }
}

void solve()
{
    //There are n node.q query.Find the total distinct connected component
    int n,q;
    cin >> n >> q;
    for(int i = 1 ;i <= n;i++)
        make(i);
    while(q--)
    {   
        string s;
        cin>>s;
        if(s == "union"){
            int u,v;
            cin >> u >> v;
                uni(u,v);   
        }
        else
        {
            int v;
            cin >> v;
            int root = find(v);
            cout << mi[root] << " " << ma[root] << siz[root] << endl;
        }
    }
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