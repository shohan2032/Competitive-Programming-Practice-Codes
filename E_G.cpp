#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    string s;
    cin >> s;
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        int ans = 0;
        for(;l < s.size();l++,r++)
        {
            if(s[l] != s[r])
                break;
            ans++;
        }   
        cout << ans << endl;
    }
    return 0;
}
/*Problem_link

*/