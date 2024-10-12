#include <bits/stdc++.h>

using namespace std;


int32_t main()
{
    string s;
    cin >>s;
    int j = s.size()-1;
    int f = 1;
    for(int i = 0;i < j;i++,j--)
    {
        if(s[i] != s[j])
        {
            f = 0;
            break;
        }
    }
    if(f == 1)
        cout << "YES" << endl;
    else    
        cout << "NO" << endl;
    return 0;
}
/*Problem_link

*/