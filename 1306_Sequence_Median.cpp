#include <bits/stdc++.h>

using namespace std;

#define db long long
#define ll long long
#define fr(cont) for (auto &i : (cont))
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.rbegin(), cont.rend()  

int main()
{
    ll n;
    cin >> n;
    vector<double> vc(n);
    fr(vc) cin>>i;
    sort(all(vc));
    if(n & 1)
        cout << fixed << setprecision(1) << vc[n/2] << endl;
    else
    {
        int x = n/2;
        int y = x-1;
        cout << fixed << setprecision(1) << (vc[x]+vc[y])/2 << endl;
    }
    return 0;
}
/*Problem_link

*/