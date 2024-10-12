#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

//ordered_set
template <typename DT>
using oset = tree<DT, null_type, less<DT>, rb_tree_tag, tree_order_statistics_node_update>;
//ordered_set for func
template <typename DT, typename FUNC>
using o_set = tree<DT, null_type, FUNC, rb_tree_tag, tree_order_statistics_node_update>;
//ordered_map
template <typename DT1, typename DT2>
using omap = tree<DT1, DT2, less<DT1>, rb_tree_tag, tree_order_statistics_node_update>;
//ordered_map for func
template <typename DT1, typename DT2, typename FUNC>
using o_map = tree<DT1, DT2, FUNC, rb_tree_tag, tree_order_statistics_node_update>;
/*
 * - less<data_type>-->    Increasingly sorted set
 * - less_equal<data_type>    --> Increasingly sorted multiset
 * - greater<data_type>    --> Decreasingly sorted set
 * - greated_equal<data_type>    --> Decreasingly sorted multiset
 * - Problem link ---> https://www.spoj.com/problems/ORDERSET/en/
*/

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
#define mo(a, b)	(((a) % (b)) + (b)) % (b)

/*
    set<int>st;
    st.insert(1); st.insert(10);
    auto it = st.begin();
    int x = *it;
    auto itt = st.end();
    itt--;
    int y = *itt;
    cout<< x << " " << y << endl;
    
    auto it = st.lower_bound(val);
    it--;
    int x = *it;
    
    map<int,int>mp;
    mp[1] = 1;
    mp[2] = 2;
    auto it = mp.begin();
    int x = it->first;
    auto itt = mp.end();
    itt--;
    int y = itt->first;
    cout<< x << " " << y << endl;

    sort(a+1,a+n+1);array 1 index based sorting
    sort(a,a+n);array 0 index based sorting
    
    bs--> l < r-1(l = m or r = m) or l <= r(l = m+1 or r = m+1)
*/
void solve()
{
  /*
    1. Think Greedy
    2. Think Brute Force
    3. Think solution in reverse order
    4. Think DP [ check constraints carefully ]
    5. Check base cases for DP and prove solution for Greedy
    6. Think Graph
  */ 
    int n,k;
    cin >> n >> k;
    vi vc(n);
    fr(vc)cin >> i;
    omap<int,pair<int,int>>val,ind;
    omap<pair<int,int>,int>t;
    for(int i = 0;i < n-1;i++)
    {
        int x = abs(vc[i] - vc[i+1]);
        // val[x] = {vc[i],vc[i+1]};
        ind[x] = {i,i+1};
        t[{vc[i],vc[i+1]}] = x;
    }
    // fr(val)
    //     cout << i.first << " " << i.second.first << " " << i.second.second << endl;
    for(int i = 1;i<= min(n,k);i++){
        fr(t)
            val[i.second]={i.first.first,i.first.second};
        
        auto itt = val.end();
        itt--;
        int x = itt->second.first;
        int y = itt->second.second;
        int mi= min(x,y);

        auto it = ind.end();
        it--;
        int xi = it->second.first;
        int yi = it->second.second;

        if(mi == x)
        {
            vc[yi] = mi;
            if(yi < n-1)
            {
                t.erase(t.find({vc[yi],vc[yi+1]}));
                t[{vc[xi],vc[yi+1]}];
            }
        }
        else
            vc[xi] = mi;
    }
    cout << accumulate(all(vc),0ll) << endl;
}   

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // auto st = clock();
    int t = 1;
    cin >> t;
    while (t--)
        solve();

    // cerr << 1.0*(clock()-st)/CLOCKS_PER_SEC << endl;
    return 0;
}
/*Problem_link

*/