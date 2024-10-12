#include <bits/stdc++.h>

using namespace std;

//Debug Function-->works for vector,map,set(dbg(stl_name)),,arrar(dbg(array_name,range))
template < typename F, typename S >ostream& operator << ( ostream& os, const pair< F, S > & p ) {return os << "(" << p.first << ", " << p.second << ")";}
template < typename T >ostream &operator << ( ostream & os, const vector< T > &v ) {os << "{";for(auto it = v.begin(); it != v.end(); ++it) {if( it != v.begin() ) os << ", ";os << *it;}return os << "}";}
template < typename T >ostream &operator << ( ostream & os, const set< T > &v ) {os << "[";for(auto it = v.begin(); it != v.end(); ++it) {if( it != v.begin() ) os << ", ";os << *it;}return os << "]";}
template < typename T >ostream &operator << ( ostream & os, const multiset< T > &v ) {os << "[";for(auto it = v.begin(); it != v.end(); ++it) {if( it != v.begin() ) os << ", ";os << *it;}return os << "]";}
template < typename F, typename S >ostream &operator << ( ostream & os, const map< F, S > &v ) {os << "[";for(auto it = v.begin(); it != v.end(); ++it) {if( it != v.begin() ) os << ", ";os << it -> first << " = " << it -> second ;}return os << "]";}
#define dbg(args...) do {cerr << #args << " : "; arif(args); } while(0)
clock_t tStart = clock();
#define timeStamp dbg("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)
void arif () {cerr << endl;}
template <typename T>void arif( T a[], int n ) {for(int i = 0; i < n; ++i) cerr << a[i] << ' ';cerr << endl;}
template <typename T, typename ... hello>void arif( T arg, const hello &... rest) {cerr << arg << ' ';arif(rest...);}

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
int INF = 1e18;
struct node
{
    int mi,cnt;
}t[4*N];

node merge(node l,node r)
{
    node ans;
    ans.mi = min(l.mi,r.mi);
    ans.cnt = 0;
    if(ans.mi == l.mi)
        ans.cnt += l.cnt;
    if(ans.mi == r.mi)
        ans.cnt += r.cnt;
    return ans;
}

void build(int node,int b,int e)//b theke e node er range
{
    if(b == e)
    {
        t[node].mi = a[b];
        t[node].cnt = 1;
        return;
    }
    int l = node*2;
    int r = node*2 + 1;
    int mid = (b+e)/2;
    build(l,b,mid);//l node er segment building
    build(r,mid+1,e);// r node er segment building
    t[node] = merge(t[l],t[r]);
}

node query(int node,int b,int e,int i,int j)//query hocche i theke j(TC-->Log(N))
{
    if(e < i or b > j)//current node er range ta query range er bahire
        return {INF,1};//return appropriate value according to question

    if(b >= i and e <= j)//current node er range ta query range er vitore
        return t[node];

    //current node er range ta query range ke intersect korse
    int l = node*2;
    int r = node*2 + 1;
    int mid = (b+e)/2;
    return merge(query(l,b,mid,i,j),query(r,mid+1,e,i,j));//Change this one according to question
}

void upd(int node,int b,int e,int i,int x)//i index er value ke update kore x banaute hobe(TC-->log(n))
{
    if(i > e or i < b)
        return;
    if(b == e and b == i)
    {
        t[node].mi = x;//single update
        t[node].cnt = 1;
        return;
    }
    int l = node*2;
    int r = node*2 + 1;
    int mid = (b+e)/2;
    upd(l,b,mid,i,x);
    upd(r,mid+1,e,i,x);
    t[node] = merge(t[l],t[r]);//Change this one according to question
}
 
void solve()
{
    int n, q;
    cin >> n >> q;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    build(1,1,n);
    while(q--)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int ind,v;
            cin >> ind >> v;
            ind++;
            upd(1,1,n,ind,v);
        }
        else
        {
            int l,r;
            cin>>l >> r;
            l++;
            node ans = query(1,1,n,l,r);
            cout << ans.mi << " " << ans.cnt << endl;
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
    https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/C
*/