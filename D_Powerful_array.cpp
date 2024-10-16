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

/*
    MO's algo
    handles offline query in O(q/sqrt(n)) usually
    maintain proper block size ~ sqrt(n)
    careful with < in query
    query indices and array indices are presumed to be 0-indexed
*/

const int block_sz = 550;
const int N = 1e5;
int freq[N],mo_cnt,mo_sum;
int ans[N];
int a[N];

//find the number of distinct element between l to r inclusive
void add(int idx)
{
    mo_cnt += freq[a[idx]]*freq[a[idx]]*a[idx];
    ++freq[a[idx]];  
}

void erase(int idx)
{
    --freq[a[idx]];
    mo_cnt -= a[idx]*freq[a[idx]]*freq[a[idx]];//change here
        //mo_sum -= a[idx] hoto jodi l to r sum chaito
}

struct query{
    int l,r,idx;
    query() { }
    query(int _l,int _r,int _i) : l(_l),r(_r),idx(_i) { }
    //1)Two queries with L in the same block are sorted as per increasing or dercreading R. 
    //2)Two queries with L in different blocks are sorted as per increasing or decreasing LB (L Block)  
    bool operator < (const query &p) const {
        if(l/block_sz != p.l/block_sz) return l < p.l;
        return ((l/block_sz) & 1) ? r > p.r : r < p.r;
    }
};

//for shorting the query this function also can be used.
bool cmp(const query &a,const query &b) {
    if(a.l == b.l)//1 number condition
        return a.r < b.r;
    return a.l/block_sz < b.l/block_sz;//2 number condition
    //return (a.l/block_sz < b.l/block_sz) || (a.l == b.l && a.r < b.r);
}

void mo(vector<query> &q)
{
    //sort(q.begin(),q.end(),cmp);//using cmp function
    sort(q.begin(),q.end());
    memset(ans,-1,sizeof(ans));
    int c_l = 0,c_r = -1;//current l and r
    fr(q)
    {
        //i.l and i.r is the required l and r i.e. given query range
        while(i.l < c_l) add(--c_l);
        while(i.r > c_r) add(++c_r);
        while(i.l > c_l) erase(c_l++);
        while(i.r < c_r) erase(c_r--);
        ans[i.idx]  = mo_cnt;
    }
}

void solve()
{
    int n,q;
    cin >> n >> q;
    for(int i = 0;i < n;i++)
        cin>>a[i];
    vector<query> que;
    for(int i = 0;i < q;i++)
    {
        int l,r;
        cin >> l >> r;
        l--;
        r--;
        que.pb(query(l,r,i));
    }
    mo(que);
    for(int i= 0;i < q;i++)
        cout << ans[i] <<endl;
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