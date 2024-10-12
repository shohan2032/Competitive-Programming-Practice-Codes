
#include <bits/stdc++.h>

using namespace std;

#define db long long
#define ll long long
#define int ll
#define vi vector<int>

const ll N = 2e5+9;
bool mark[N];
vi vc;
void s()
{
    mark[0] = mark[1] = 1;//mark.set(0),mark.set(1);ei vabeo likha jaito
    for(ll i = 2;i < N;i++)
    {
        if(!mark[i])
        {
            vc.push_back(i);
            for(ll j = i+i;j < N;j += i)
                mark[j] = 1;//mark.set(j);
        }
    }
}

int ma[200009],mb[200009],primeA[200009],primeB[200009];
void solve()
{


    for(int i = 1;i <=200009;i++)
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
    int cur = 0;
    for(int i = m1;i >= 2;i--)
    {
        cur += ma[i];
        ma[i] = cur;
    }
    cur = 0;
    for(int i = m2;i >= 2;i--)
    {
        cur += mb[i];
        mb[i] = cur;
    }
    // for(int i = 2;i <= m1;i++)
    //     cout << i << " " << ma[i] << endl;
    int f = 0;
    for(int i = 2;i <= max(m1,m2);i++)
    {
        if(ma[i] == mb[i])
            continue;
        if(ma[i] > mb[i])
        {
            int cur = ma[i]-mb[i];
            // cout << cur << endl;
            int x = i;
            for(int j = 0;j < vc.size() and j*j <= x;j++)
            {
                if(x % vc[j] == 0)
                {
                    int cnt = 0;
                    while(x % vc[j] == 0)
                    {
                        cnt++;
                        x /= vc[j];
                    }
                    cnt *= cur;
                    primeA[vc[j]] += cnt;
                }
            }
            if(x > 1)
                primeA[x] += cur;
        }
        else
        {
            int cur = mb[i]-ma[i];
            // cout << cur << endl;
            int x = i;
            for(int j = 0;j < vc.size() and j*j <= x;j++)
            {
                if(x % vc[j] == 0)
                {
                    int cnt = 0;
                    while(x % vc[j] == 0)
                    {
                        cnt++;
                        x /= vc[j];
                    }
                    cnt *= cur;
                    primeB[vc[j]] += cnt;
                    f = max(f,vc[j]);
                }
            }
            if(x > 1){
                primeB[x] += cur;
                f = max(f,x);
            }
        }
    }
    // fr(primeA)
    //     cout << i.first << " " << i.second << endl;
    // cout << endl;
    // fr(primeB)
    //     cout << i.first << " " << i.second << endl;
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
    s();
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
