//ALL POSSIBLE SUBSET
#include<bits/stdc++.h>
using namespace std;
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] =>", dbg_out(__VA_ARGS__)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Up, typename... Down> void dbg_out(Up U, Down... D) { cerr << ' ' << U; dbg_out(D...); }
 
typedef long long ll;
#define pb push_back

void rTime(){
    cerr<<"Time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
    if(((float)clock()/CLOCKS_PER_SEC)>=1.0)
        cerr<<"Need to optimize!!"<<endl;
    else
        cerr<<"RuntimeOKAY!"<<endl<<endl;
}
ll fre[101];
int main() 
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("C://Users//ooo//OneDrive//c++//C++//input.txt", "r",stdin);
    //freopen("C://Users//ooo//OneDrive//c++//C++//output.txt", "w", stdout);
    int a[10010]={0},i,j,n,t,k,d,x,y,num,cnt=0;
    vector<int>v;

    /* input >
    3
    1 2 3 */
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        v.push_back(x);
    }
    ///complexity = O(2^n*n)
    for(int mask=1;mask<(1<<n);mask++)
    {
        for(i=0;i<n;i++)
        {
            if(mask & (1<<i))
                cout<<v[i]<<' ';
        }
        cout<<endl;             
    }
 
    rTime();
return 0;
}