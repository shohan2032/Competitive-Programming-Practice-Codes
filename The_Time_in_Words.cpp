#include <bits/stdc++.h>

using namespace std;

#define db long long
#define ll long long
#define int ll
#define vi vector<int>
#define vs vector<string>
#define vpi vector<pair<int, int>>
#define vpd vector<pair<double, double>>
#define vps vector<pair<string, string>>
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
#define fr(cont) for (auto &i : (cont))
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.rbegin(), cont.rend()
#define mo(a, b) (((a) % (b)) + (b)) % (b)
#define endl '\n'

string one[] = { "", "one ", "two ", "three ", "four ",
                 "five ", "six ", "seven ", "eight ",
                 "nine ", "ten ", "eleven ", "twelve ",
                 "thirteen ", "fourteen ", "fifteen ",
                 "sixteen ", "seventeen ", "eighteen ",
                 "nineteen " };
                 
string ten[] = { "", "", "twenty ", "thirty ", "forty ",
                 "fifty ", "sixty ", "seventy ", "eighty ",
                 "ninety " };
string lokkho(int n)
{
    string lokkho_part;
    n %= 10000000;
    n /= 100000;
    if(n <= 19)
        lokkho_part += one[n];
    else
        lokkho_part += ten[n/10],lokkho_part += one[n%10];
    if(lokkho_part.size())
        lokkho_part += "lakh ";
    return lokkho_part;
}
string hajar(int n)
{
    string hajar_part;
    n %= 100000;
    n /= 1000;
    if(n <= 19)
        hajar_part += one[n];
    else
        hajar_part += ten[n/10],hajar_part += one[n%10];
    if(hajar_part.size())
        hajar_part += "thousand ";
    return hajar_part;
}
string shotok(int n)
{
    string shotok_part;
    n %= 1000;
    shotok_part = one[n/100];
    if(shotok_part.size())
        shotok_part += "hundred ";
    return shotok_part;
}
string doshok(int n)
{
    string doshok_part;
    n %= 100;
    if(n <= 19)
        doshok_part = one[n];
    else
        doshok_part = ten[n/10]+one[n%10];
    return doshok_part;
}
string kuti(int n)
{
    string kuti_part;
    n /= 10000000;
    kuti_part += lokkho(n);
    kuti_part += hajar(n);
    kuti_part += shotok(n);
    kuti_part += doshok(n);
    if(kuti_part.size())
        kuti_part += "crore ";
    return kuti_part;
}
string convertIntToWord(int n)
{
    string ans;
    ans += kuti(n);
    ans += lokkho(n);
    ans += hajar(n);
    ans += shotok(n);
    ans += doshok(n);
    return ans;
}
void solve()
{
    int h,m;
    cin>> h >> m;
    if(m==0)
        cout << convertIntToWord(h) << "o' " << "clock" << endl;
    else if(m==15)
        cout << "quarter past " << convertIntToWord(h) << endl;
    else if(m == 45)
    {
        if(h < 12)
            cout << "quarter to " << convertIntToWord(h+1) << endl;
        else
            cout << "quarter to " << convertIntToWord(1) << endl;
    }
    else if(m == 30)
        cout << "half past " << convertIntToWord(h) << endl;
    else
    {
        if(m < 30)
        {
            if(m==1)
                cout << "one minute past ";
            else
            {
                if(m <= 19)
                    cout << convertIntToWord(m) << "minutes past ";
                else
                {
                    cout << convertIntToWord(m);
                    cout << "minutes past ";
                }
            }
            cout << convertIntToWord(h) << endl;
        }
        else
        {
            m = 60-m;
            if(m==1)
                cout << "one minute to ";
            else
            {
                if(m <= 19)
                    cout << convertIntToWord(m) << "minutes to ";
                else
                {
                    cout << convertIntToWord(m);
                    cout << "minutes to ";
                }
            }
            if(h < 12)
                cout << convertIntToWord(h+1) << endl;
            else
                cout << convertIntToWord(1) << endl;
        }
    }
}   

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // auto st = clock();
    int t = 1;
    // cin >> t;
    for(int i = 1;i <= t;i++)
    {
        // cout << "Case " << i << ": ";
        solve();
    }

    // cerr << 1.0*(clock()-st)/CLOCKS_PER_SEC << endl;
    return 0;
}
/*Problem_link

*/