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

const ll N = 500;//1e8+9 pojjonto run kore sudu codeblocks a.
bool mark[N];
set<int> vc;
void s()
{
    mark[0] = mark[1] = 1;//mark.set(0),mark.set(1);ei vabeo likha jaito
    for(ll i = 2;i < N;i++)
    {
        if(!mark[i])
        {
            vc.insert(i);
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
    int n;
    cin >> n;
    vi v;
    map<int,vi>mp;
    for(int i = 1;i <= n;i++)
    {
        int x;
        cin>>x;
        v.pb(x);
        mp[x].pb(i);
    }
    fr(v)
    {
        int x= i;
        for(int j = 1;j+x <= 200;j++)
        {
            if(!vc.count(x+j) and mp.count(j))
            {
                if(x==j)
                {
                    if(mp[x].size() >= 2)
                    {
                        int a = mp[x].back();
                        mp[x].pop_back();
                        int b = mp[x].back();
                        cout << a << " " << b << endl;
                        return;
                    }
                }
                else
                {
                    cout << mp[x].back() << " " <<  mp[j].back() << endl;
                    return;
                }
                
            }
        }
    }
    cout << -1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //auto st = clock();
     s();
     int t = 1;
     cin >> t;
     while(t--)
         solve();

    //cerr << 1.0*(clock()-st)/CLOCKS_PER_SEC << endl;
    return 0;
}
