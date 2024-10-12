#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
    oset<pair<int,int>> s;

    int n;
    cin>> n;
    for(int i = 1;i <= n;i++)
    {
        int x;
        cin>> x;
        s.insert({i,x});
    }

    for(int i = 1;i <= n;i++)
    {
        int ind;
        cin>>ind;
        ind--;
        int x =  (*s.find_by_order(ind)).first;
        int y = (*s.find_by_order(ind)).second;
        cout << y << " ";
        s.erase({x,y});
    }

    // s.insert(make_pair(1,2));
    // s.insert(make_pair(2,6));
    // s.insert(make_pair(3,1));
    // s.insert(make_pair(4,4));
    // s.insert(make_pair(5,2));

    // int x =  (*s.find_by_order(2)).first;
    // int y = (*s.find_by_order(2)).second;
    // cout << x << " " << y << endl;
    // s.erase(make_pair(x,y));
    // x =  (*s.find_by_order(2)).first;
    // y = (*s.find_by_order(2)).second;
    // cout << x << " " << y << endl;
}