#include <bits/stdc++.h>

using namespace std;

#define db long long
#define ll long long
#define int ll
#define vi vector<int>

const ll N = 2e5 + 9;
int spf[N];
int ma[200009],mb[200009],primeA[200009],primeB[200009];
void function_for_spf()//Time Complexity of this function is O(N*log(log(N))).this is the pre-calculeted function for spf;
{
  for (ll i = 2; i < N; i++)
    spf[i] = i;
  for (ll i = 2; i*i <= N; i++) 
  {
     if(spf[i] == i)
     {
        for (ll j = i+i; j < N; j += i)
          if(spf[j] == j)
             spf[j] = i;
     }   
  }
}


void solve()
{
    for(int i = 1;i <=200000;i++)
    {
        ma[i] = 0;
        mb[i] = 0;
        primeA[i] = 0;
        primeB[i] = 0;
    }
    int n,m;
    cin >> n>> m;
    int m1 = 0,m2 = 0;
    for(int i = 1;i <= n;i++)
    {
        int x;
        cin >> x;
        m1 = max(m1,x);
        ma[x]++;
    }
    for(int i = 1;i <= m;i++)
    {
        int x;
        cin >> x;
        m2 = max(m2,x);
        mb[x]++;
    }
    int cur1 = 0,cur2 = 0,f = 0;
    for(int i = max(m1,m2);i >= 2;i--)
    {
        cur1 += ma[i];
        cur2 += mb[i];
        int x = i;
        while(x != 1)
        {
            primeA[spf[x]] += cur1;
            primeB[spf[x]] += cur2;
            f = max(f,spf[x]);
            x /= spf[x];
        }
    }
    for(int i = 2;i <= f;i++)
    {
        if(primeB[i] > primeA[i])
        {
            cout << 1 << endl;
            return;
        }
    }
    cout << 0 << endl;
}   

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    function_for_spf();
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