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

const int N = 5e5 + 9;
int a[N];
struct ST {
    #define lc (n << 1)
    #define rc ((n << 1) + 1)
    int t[4*N],lazy[4*N];
    ST(){
        memset(t,0,sizeof(t));
        memset(lazy,0,sizeof(lazy));
    }

    //parent er main value and child gulor lazy value update korar function
    inline void push(int n,int b,int e)//change this
    {
        if(lazy[n] == -1)
            return;
        t[n] = lazy[n];//parent node er value update
        if(b != e)
        {
            lazy[lc] = lazy[n];//left child er lazy value update
            lazy[rc] = lazy[n];//right child er lazy value update
        }
        lazy[n] = -1;//jehetu parent node er child er lazy value update kore pelsi so parent er lazy 0 kore dite hobe
    }

    //value merge kore return korbe query er jonno
    inline int combine(int a,int b)//change this 
    {
        return min(a,b);
    }

    //parent node er value save korar function
    inline void pull(int n)//change this
    {
        t[n] = min(t[lc],t[rc]);
    }

    //building the tree 
    inline void build(int n,int b,int e)
    {
        lazy[n] = -1;//change this
        if(b == e)
        {
            t[n] = a[b];
            return;
        }
        int mid = (b+e)/2;
        build(lc,b,mid);
        build(rc,mid+1,e);
        pull(n);
    }

    //updating the value in a segment
    inline void upd(int n,int b,int e,int i,int j,int x)
    {
        push(n,b,e);
        if(e < i or b > j)
            return;
        if(b >= i and e <= j)
        {
            lazy[n] = x;//set lazy
            push(n,b,e);//ei line na korleo hobe
            return;
        }
        int mid = (b+e)/2;
        upd(lc,b,mid,i,j,x);
        upd(rc,mid+1,e,i,j,x);
        pull(n);
    }

    inline int query(int n,int b,int e,int i,int j)
    {
        push(n,b,e);
        if(e < i or b > j)
            return 1e18;
        if(b >= i and e <= j)
            return t[n];
        int mid = (b+e)/2;
        return combine(query(lc,b,mid,i,j),query(rc,mid+1,e,i,j));
    }
}t;

void solve()
{
    int n,q;
    cin >> n >> q;
    t.build(1,1,n);//building the tree
    while(q--)
    {
        int ty;
        cin >> ty;
        if(ty == 1)
        {
            int l,r,val;
            cin>> l >> r >>val;
            l++;
            t.upd(1,1,n,l,r,val);
        }
        else
        {
            int l,r;
            cin >> l >> r;
            l++;
            cout << t.query(1,1,n,l,r) << endl;
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