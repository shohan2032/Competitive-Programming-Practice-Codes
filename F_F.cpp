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

const ll N = 1e6+9;//1e8+9 pojjonto run kore sudu codeblocks a.
bool mark[N];
set<ll> vc;
void s()
{
    mark[0] = mark[1] = 1;
    for(ll i = 2;i < N;i++)
    {
        if(!mark[i])
        {
            vc.insert(i);
            for(ll j = i+i;j < N;j += i)
                mark[j] = 1;
        }
    }
    
}

bool f(int n)
{
    if(n == 1)
        return false;
    for(int i = 2;i*i <= n;i++)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}

void solve()
{
    ll n;
    cin>> n;
    if(vc.count(n))
    {
        cout << 1 << endl << n << endl;
        return;
    }
    fr(vc)
    {
        if(i > n)
            break;
        if(f(n-i))
        {
            cout << 2 << endl << i << " " << n-i << endl;
            return;
        }
    }

    int cnt = 0;
    fr(vc)
    {
        if(cnt > 100 or i > n)
            break;
        int x = n-i;
        for(auto &j:vc)
        {
            if(j > x)
                break;
            if(f(x-j))
            {
                cout << 3 << endl << i << " " << j << " " << x-j << endl;
                return;
            }
        }
        cnt++;
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //auto st = clock();
     s();
     int t = 1;
    //  cin >> t;
     while(t--)
         solve();

    //cerr << 1.0*(clock()-st)/CLOCKS_PER_SEC << endl;
    return 0;
}
