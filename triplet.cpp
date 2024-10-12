#include <bits/stdc++.h>

using namespace std;
#define ll long long int
const ll N = 1e7 + 9;
int spf[N];
void s()//TC-N*(log(log(N)))
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
	int x,y;
	cin >> x >> y;
	int a,b,c,gcd_of_b_c;
	b = (x+y)/2;
	c = (x-y)/2;
	gcd_of_b_c = __gcd(b,c);
	a = spf[gcd_of_b_c];
	cout << a << " " << b << " " << c << endl;
}   

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	s();
	int t = 1;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
/*Problem_link
    12
    1999998 2      --> 2 1000000 999998
    14 0           --> 7 7 7 
    1210000 990000 --> 2 1100000 110000
    1999990 10     --> 2 1000000 999990
    2000000 0      --> 2 1000000 1000000
    1000000 0      --> 2 500000 500000
    4 0            --> 2 2 2
    300009 299991  --> 3 300000 9
    369 205        --> 41 287 82
    102 0          --> 3 51 51
    132 110        --> 11 121 11
    30 18          --> 2 24 6
*/
/*intput:
12
1999998 2
14 0 
1210000 990000
1999990 10
2000000 0 
1000000 0 
4 0
300009 299991
369 205
102 0
132 110
30 18 


output:
2 1000000 999998
7 7 7
2 1100000 110000
2 1000000 999990
2 1000000 1000000
2 500000 500000
2 2 2
3 300000 9
41 287 82
3 51 51
11 121 11
2 24 6
*/