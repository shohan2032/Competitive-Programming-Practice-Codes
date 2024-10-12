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

const int N = 1e5 + 9;
int a[N];
int bit_cnt[N*4][25];
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
        if(lazy[n] == 0)
            return;
        int x = lazy[n];
        int new_val = t[n];
        for(int i = 20;i >= 0;i--)
        {
            if(x&(1ll<<i))
            {
                int o = bit_cnt[n][i];
                int z = (e-b+1) - o;
                new_val -= (1ll<<i)*o;
                new_val += (1ll<<i)*z;
                bit_cnt[n][i] = z;
            }
        }
        t[n] = new_val;//parent node er value update
        if(b != e)
        {
            lazy[lc] = lazy[lc] ^ lazy[n];//left child er lazy value update
            lazy[rc] = lazy[rc] ^ lazy[n];//right child er lazy value update
        }
        lazy[n] = 0;//jehetu parent node er child er lazy value update kore pelsi so parent er lazy 0 kore dite hobe
    }

    //value merge kore return korbe query er jonno
    inline int combine(int a,int b)//change this 
    {
        return a+b;
    }

    //parent node er value save korar function
    inline void pull(int n)//change this
    {
        t[n] = t[lc] + t[rc];
        for(int i = 20;i >= 0;i--)
            bit_cnt[n][i] = bit_cnt[lc][i] + bit_cnt[rc][i];
    }

    //building the tree 
    inline void build(int n,int b,int e)
    {
        lazy[n] = 0;//change this
        if(b == e)
        {
            t[n] = a[b];
            for(int i=20;i >= 0;i--)
            {
                if((a[b]&(1ll<<i)))
                    bit_cnt[n][i]++;
            }
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
            return 0;
        if(b >= i and e <= j)
            return t[n];
        int mid = (b+e)/2;
        return combine(query(lc,b,mid,i,j),query(rc,mid+1,e,i,j));
    }
}t;

void solve()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    t.build(1,1,n);//building the tree
    int q;
    cin>> q;
    while(q--)
    {
        int ty;
        cin>>ty;
        if(ty == 1){
            int l ,r;
            cin>> l >> r;
            cout << t.query(1,1,n,l,r) << endl;
        }
        else
        {
            int l,r,val;
            cin>> l >> r >> val;
            t.upd(1,1,n,l,r,val);
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