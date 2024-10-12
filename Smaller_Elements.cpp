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

int main()
{
    int t;
    cin>> t;
    while(t--)
    {
        oset<pair<int,int>> s;
        int n;
        cin>> n;
        vector<int> vc;
        for(int i= 0;i < n;i++)
        {
            int x;
            cin>>x;
            s.insert({x,i});
            vc.push_back(x);
        }
        long long int ans = 0;
        for(int i = 0;i < n;i++)
        {
            int p = s.order_of_key({vc[i],i});
            s.erase(s.find({vc[i],i}));
            // if(*s.find_by_order(p) >= vc[i])
            //     p--;
            // cout << p << endl;
            ans += p;
        }
        cout << ans << endl;
    }
    

    
}
/*Problem_link
    https://cses.fi/problemset/task/1749
    https://cses.fi/problemset/task/1144
*/