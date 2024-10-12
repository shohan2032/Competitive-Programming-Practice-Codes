/*  -------------------------      Namo Buddhaya        ------------------------   */

/*

    It's Only Pain Which Lead's Us To Achieve Some Thing Special.

*/

#include <bits/stdc++.h>
using namespace std;

#define debug(i) cout << "Debug " << i << nl
#define nl "\n"
#define sp " "
#define ll long long int
#define ld long double
#define PI 2 * acos(0.0)
#define mem(arr, fix) memset(arr, fix, sizeof(arr))
#define eps 1e-6
#define mkp make_pair
#define valid(nx, ny, rowx, colx) (nx >= 1 && nx <= rowx) && (ny >= 1 && ny <= colx)
#define Dpos(n) fixed << setprecision(n)
#define ff first
#define ss second
#define vi vector<int>
#define vl vector<long long int>
#define mod ((ll)1e9 + 7)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()
#define allrev(v) v.rbegin(), v.rend()
#define vin(name) \
    ll num;       \
    cin >> num;   \
    name.push_back(num);

/*
Handle: tmp4pfm.36
Password: 8CXNZKLY
*/

// Global Variable && Functions

// Main Codes Start Here
void Solve()
{
    int n;
    vector<ll> ar;
    set<int> st, tmp_st;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        ll num;
        cin >> num;
        ar.push_back(num);
        st.insert(i);
    }

    ll ans = 0;
    ll mx = 0;

    for (int step = 0; step < n; step++)
    {
        bool flag = false;
        vector<ll> tmp_ar;
        for (auto x : st)
        {
            tmp_ar.push_back(x);
        }
        ll pos = 0;
        ll tmp = 0;
        for (int i = 0; i < tmp_ar.size(); i++)
        {
            if (i == 0 and i + 1 < tmp_ar.size())
            {
                if (tmp < ar[tmp_ar[i]])
                {
                    tmp = ar[tmp_ar[i + 1]];
                    pos = tmp_ar[i];
                    flag = true;
                }
            }
            else if (i != 0 and i + 1 == tmp_ar.size())
            {
                if (tmp < ar[tmp_ar[i - 1]])
                {
                    tmp = ar[tmp_ar[i - 1]];
                    pos = tmp_ar[i];
                    flag = true;
                }
            }
            else if (i - 1 >= 0 and i + 1 < tmp_ar.size())
            {
                ll mul = ar[tmp_ar[i - 1]] * ar[tmp_ar[i + 1]];
                if (tmp < mul)
                {
                    tmp = mul;
                    pos = tmp_ar[i];
                    flag = true;
                }
            }
            else
            {
                tmp = ar[tmp_ar[i]];
                pos = tmp_ar[i];
            }
        }
        // cout << tmp << sp << pos << endl;
        ans += tmp;
        st.erase(pos);
    }

    cout << ans << nl;
}

// Main Function
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //:]

    int t = 1;

    // cin >> t;

    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ":";
        //  cout << "Case " << i << ": ";
        Solve();
    }

    return 0;
}