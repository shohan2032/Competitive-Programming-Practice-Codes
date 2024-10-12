#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s1,s2;
    cin >> s1 >> s2;
    if(s1 == s2)
        cout << "YES" << endl << s1 << endl;
    else
    {
        if(s1[0] == s2[0])
            cout << "YES" << endl << s1[0] << '*' << endl;
        else if(s1[s1.size()-1] == s2[s2.size()-1])
            cout << "YES" << endl << '*' << s1[s1.size()-1] << endl;
        else
        {
            if(s1.size() > s2.size()) swap(s1,s2);
            for(int i = 0;i < s1.size()-1;i++)
            {
                string an = s1.substr(i,2);
                if(s2.find(an) != string::npos)
                {
                    cout << "YES" << endl << '*' << an << '*' << endl;
                    return;
                }
            }
            cout << "NO" << endl;
        }
    }
}   

int main()
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