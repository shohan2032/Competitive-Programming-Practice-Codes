#include <bits/stdc++.h>

using namespace std;

#define db long long
#define ll long long
#define vi vector<int>
#define vs vector<string>
#define vl vector<ll>
#define pii pair<int,int>
#define vpi vector < pair <int,int> >
#define vpl vector < pair <ll,ll> >
#define vpd vector < pair <double,double> >
#define vps vector < pair <string,string> >
#define mp make_pair
#define f first
#define s second
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
#define loop1 for(i = 0;i < n;i++)
#define loop2 for(j = 0;j < n;j++)
#define fr(cont) for(auto &i : (cont))
#define all(cont) cont.begin(),cont.end()
#define rall(cont) cont.rbegin(),cont.rend()
#define inv a,b,i,j,k,l,r,t,q,cnt1 = 0,cnt2 = 0,x,y,z,n,cnt = 0,ma = INT_MIN,mi = INT_MAX,sum = 0

const ll N = 1e5+9;//1e8+9 pojjonto run kore sudu codeblocks a.
bool mark[N];
vl vc;
void s()
{
    mark[0] = mark[1] = 1;//mark.set(0),mark.set(1);ei vabeo likha jaito
    for(ll i = 2;i < N;i++)
    {
        if(!mark[i])
        {
            vc.pb(i);
            for(ll j = i+i;j < N;j += i)
                mark[j] = 1;//mark.set(j);
        }
    }
    // for(int i = 0;i < vc.size();i++)
    //     cout << vc[i] << endl;
    // cout << vc.size();
}


void solve()
{
    ll n;
    cin>> n;
    // ll o = 0;
    // for(ll i = 0;i < vc.size() and i*i <= n;i++)
    // {
    //     if(n % vc[i] == 0)
    //     {
    //         while(n % vc[i] == 0){
    //             if(vc[i] & 1)
    //                 o++;
    //             n /= vc[i];
    //         }
    //     }
    // }
    // if(n > 1)
    // {
    //     if(n&1)
    //         o++;
    // }
    if(n & 1 and n != 1)
        cout << "Alice" << endl;
    else    
        cout << "Bob" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //auto st = clock();
    //  s();
     int t = 1;
     cin >> t;
     while(t--)
         solve();

    //cerr << 1.0*(clock()-st)/CLOCKS_PER_SEC << endl;
    return 0;
}
