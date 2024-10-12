#include <bits/stdc++.h>

using namespace std;

#define Safid_Anir ios_base::sync_with_stdio(false);cin.tie(NULL);
#define l(x)  (int)(x).size()
#define all(x)  (x).begin(),(x).end()
#define rall(x)  (x).rbegin(),(x).rend()
#define alll(x) (x).begin(),(x).end(),(x).begin()
#define sp " "
#define nl '\n'
#define vi vector<int>
#define vs vector<string>
#define vl vector<ll>
#define pii pair<int, int>
#define vpi vector<pair<int, int>>
#define vpl vector<pair<ll, ll>>
#define vpd vector<pair<double, double>>
#define vps vector<pair<string, string>>
#define pb push_back
#define pf push_front
#define pof pop_front
#define pob pop_back
#define ps partial_sum
#define ite iterator
#define pq priority_queue
#define ll long long
#define f(x,y) for(long long x=0;x<y;x++)
#define pi 2*acos(0.0)

void solve()
{
    ll n,k,t;
    cin >> n >> k;
    t=n;
    string s;
    cin >> s;
    ll v[26] = {0};
    f(i,l(s))
    {
        v[s[i]-'a']++;
    }
    //print(v);
    string ss;
    while(n>0)
    {
        ll d=t/k;
        for(ll i=0; i< 26;)
        {
            if(v[i]==0)
            {
                ss+=i+'a';
                n-=d;
                while(d>0)
                {
                    i--;
                    if(v[i]>=d)
                    {
                        v[i]-=d;
                        d=0;
                    }
                    else
                    {
                        v[i]=0;
                        d-=v[i];
                    }
                }
                //print(v);
                break;
            }
            else
                i++;
        }
    }
    cout << ss << nl;
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