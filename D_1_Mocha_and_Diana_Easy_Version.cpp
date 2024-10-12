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

int const N = 3e5+9;
// int siz[N],parent[N];

//overall TC of DSU is constant.O(alpha(N)) --> reversed ackerman function..It increase very slowly.That is almost N.
void make(int n,vi &parent,vi &siz)//add new node to our current sets
{
    parent[n] = n;
    siz[n] = 1;
}

int find(int n,vi &parent)//return the root of that set where the node n belonged to.
{
    if(parent[n] == n)
        return n;
    return parent[n] = find(parent[n],parent);//path compression
}

void uni(int a,int b,vi &parent,vi &siz)//set node a and b to the same group
{
    a = find(a,parent);//a node er root ta finding
    b = find(b,parent);//b node er root ta finding

    if(a != b)//when both a and b are not belonged to the same set
    {
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
    //There are n node.q query.Find the total distinct connected component
    int n,q1,q2;
    cin >> n >> q1 >> q2;
    vi par1(n+5),par2(n+5),siz1(n+5),siz2(n+5);
    for(int i = 1 ;i <= n;i++){
        make(i,par1,siz1);
        make(i,par2,siz2);
    }
    while(q1--)
    {   
        int u,v;
        cin>> u >> v;
        uni(u,v,par1,siz1);
    }
    while(q2--)
    {   
        int u,v;
        cin>> u >> v;
        uni(u,v,par2,siz2);
    }
    vpi ans;
    for(int i = 1;i <= n;i++)
    {
        if(find(i,par1) != find(1,par1) and find(i,par2) != find(1,par2))
        {
            ans.pb(mp(1,i));
            uni(1,i,par1,siz1);
            uni(1,i,par2,siz2);
        }
    }
    int l = 1,r = 1;
    while(l <= n and r <=  n)
    {
        while(l <= n and find(l,par1) == find(1,par1))
            l++;
        while(r <= n and find(r,par2) == find(1,par2))
            r++;
        if(l > n or r > n)
            break;
        ans.pb(mp(l,r));
        uni(1,l,par1,siz1);
        uni(1,r,par2,siz2);
    }
    cout << ans.size() << endl;
    fr(ans)
        cout << i.first << " " <<i.second << endl;
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
        https://codeforces.com/problemset/problem/1213/G
*/