#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define vs vector<string>
#define vl vector<ll ll>
#define vpi vector < pair <int,int> >
#define vpl vector < pair <ll,ll> >
#define vpd vector < pair <double,double> >
#define vps vector < pair <string,string> >
#define mp make_pair
#define f first
#define s second
#define pythagoras sqrt( (pow((x2-x1),2)) + (pow((y2-y1),2)) )///for two ending points
#define PI (acos(-1.0))
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
#define EPS (1e-9)
#define loop1 for(i = 0;i < n;i++)
#define loop2 for(j = 0;j < n;j++)
#define fr for(auto &i : vc)
#define all(cont) cont.begin(),cont.end()
#define rall(cont) cont.rbegin(),cont.rend()
#define inv a,b,i,j,k,l,r,t,q,cnt1 = 0,cnt2 = 0,x,y,z,n,cnt = 0,ma = INT_MIN,mi = INT_MAX,sum = 0
#define sv s1,s,s2,s3,s4
/*BS
    cin >> y;
    bool found = false;
    l = 0;
    r = n-1;
    while(l <= r)
    {
      m = (l+r)/2;
      if(vc[m] == y)
      {
        found = true;
        break;
      }
      else if(y > vc[m])
      {
        l = m+1;
      }
      else
        r = m-1;
    }
    if(found)
      cout << "YES\n";
    else
      cout << "NO\n";
*/
/*LB__UB
    l = -1,r = n;
        while(l + 1 != r)
        {
            m = l+r/2;
            if(vc[m] >= x)///if(vc[m] > x) for upper bound
                r = m;
            else
                l = m;",
        }
        cout << r;
*/


void solve()
{
    string s;
    cin >> s;
    vector<char> vc;
    for(int i = 0;i < s.size();i++)
    {
        if(toupper(s[i]) == 'A' || toupper(s[i]) == 'E' || toupper(s[i]) == 'I' || toupper(s[i]) == 'O' || toupper(s[i]) == 'U' || toupper(s[i]) == 'Y')
            continue;
        else
        {
            vc.pb('.');
            vc.pb(tolower(s[i]));
        }
    }
    for(int i = 0;i < vc.size();i++)
        cout << vc[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     int t = 1;
     ///cin >> t;
     while(t--)
         solve();

    return 0;
}