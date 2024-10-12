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
int t[4*N];//saving the sum of segment in the tree

void build(int node,int b,int e)//b theke e node er range
{
    if(b == e)
    {
        t[node] = a[b];
        return;
    }
    int l = node*2;
    int r = node*2 + 1;
    int mid = (b+e)/2;
    build(l,b,mid);//l node er segment building
    build(r,mid+1,e);// r node er segment building
    t[node] = t[l]+t[r];//saving the sum of this node.Change this one according to question
}

int query(int node,int b,int e,int k)//query hocche i theke j(TC-->Log(N))
{
    if(b == e)
        return b;
    //current node er range ta query range ke intersect korse
    int l = node*2;
    int r = node*2 + 1;
    int mid = (b+e)/2;
    if(t[l] >= k)
        return query(l,b,mid,k);
    else
        return query(r,mid+1,e,k-t[l]);//Change this one according to question
}

void upd(int node,int b,int e,int i)//i index er value ke update kore x banaute hobe(TC-->log(n))
{
    if(i > e or i < b)
        return;
    if(b == e and b == i)
    {
        t[node] = 1 - t[node];//single update
        return;
    }
    int l = node*2;
    int r = node*2 + 1;
    int mid = (b+e)/2;
    upd(l,b,mid,i);
    upd(r,mid+1,e,i);
    t[node] = (t[l]+t[r]);//Change this one according to question
}
 
void solve()
{
    int n,q;
    cin >> n >> q;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    build(1,1,n);
    while(q--)
    {
        int ty;
        cin>>ty;
        if(ty == 1)
        {
            int ind;
            cin>> ind;
            ind++;
            upd(1,1,n,ind);
        }
        else
        {
            int ind;
            cin>> ind;
            cout << query(1,1,n,ind+1)-1 << endl;
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