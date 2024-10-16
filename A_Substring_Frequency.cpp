#include<bits/stdc++.h>
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
#define endl '\n'

const int lim = 1e6 + 5 ; 

namespace suff{
    int n ;
    string str ;
    vector<int> SA, _rank, lcp ;
    int table[20][lim] ;

    

    void count_sort(){
        vector<int> cnt(n) ;
        for(int i: _rank)
            cnt[i]++ ;

        vector<int> SA_new(n), left_idx(n) ;
        left_idx[0] = 0 ;

        for(int i=1; i<n; i++)
            left_idx[i] = left_idx[i-1] + cnt[i-1] ;

        for(int i: SA){
            int id = _rank[i] ;
            SA_new[ left_idx[id] ] = i ;
            left_idx[id]++ ;  
        }
        SA = SA_new ;
    }

    void build_suffix_array(){
        vector<pair<char, int> > arr(n) ;
        for(int i=0; i<n; i++)
            arr[i] = {str[i], i} ;
        sort(arr.begin(), arr.end()) ;

        for(int i=0; i<n; i++) SA[i] = arr[i].second ;
        _rank[ SA[0] ] = 0 ;

        for(int i=1; i<n; i++){
            _rank[ SA[i] ] = _rank[ SA[i-1] ] ;
            if(arr[i].first != arr[i-1].first)
                _rank[ SA[i] ]++ ;
        }

        for(int k=0; (1<<k) < n; k++){
            for(int i=0; i<n; i++)
                SA[i] = ( SA[i] - (1<<k) + n ) % n ;
            count_sort() ;

            vector<int> _rank_new(n) ;
            _rank_new[ SA[0] ] = 0 ;

            for(int i=1; i<n; i++){
                pair<int,int> prev = { _rank[ SA[i-1] ], _rank[ (SA[i-1] + (1<<k))%n ] } ;
                pair<int,int> cur = { _rank[ SA[i] ], _rank[ (SA[i] + (1<<k))%n ] } ;

                _rank_new[ SA[i] ] = _rank_new[ SA[i-1] ] ;
                if(cur != prev) _rank_new[ SA[i] ]++ ;
            }
            _rank = _rank_new ;
        }
    }
    void init(string _str){
        str = _str + " " ;//change the time separator charachter if you face run time.space-->&,$,# 
        n = str.size() ;
        SA.resize(n) ;
        _rank.resize(n) ;
        lcp.resize(n) ;
        build_suffix_array() ;
    }

    void build_lcp(){
        int k = 0 ;
        for(int i=0; i<n-1; i++){
            int pi = _rank[i] ;
            int j = SA[ pi-1 ] ; 
            while(str[ i+k ] == str[ j+k ]) k++ ;
            lcp[ pi ] = k ;
            k = max(0ll, k-1) ;
        }
    }

    void build(){
        for(int i=0; i<n; i++)
            table[0][i] = lcp[i] ;

        for(int i=1; (1<<i)<=n; i++){
            for(int j=0; j+(1<<i)<=n; j++){
                int x = table[i-1][j] ;
                int y = table[i-1][j+(1 << (i-1))] ; 
                table[i][j] = min(x, y) ;
            }
        }
        //if you want to delete the empty suffix
        // reverse(all(SA));
        // SA.pop_back();
        // reverse(all(SA));
    }

    int query(int lo,int hi){
        lo = _rank[lo] , hi = _rank[hi] ;
        if(hi < lo) swap(lo, hi) ;
        if(lo == hi) return n-SA[lo]-1 ;
        lo++ ;
        int i = log2(hi-lo+1) ;
        int x = table[i][lo] ;
        int y = table[i][hi-(1<<i)+1] ;
        return min(x, y) ;
    }

    int lower_bound(string &s,string &t) {
        int n = s.size();
        int l = 0, r = n - 1, k = t.size(), ans = n;
        while (l <= r) {
            int mid = l + r >> 1;
            if (s.substr(SA[mid], min(n - SA[mid], k)) >= t) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        return ans;
    }

    int upper_bound(string &s,string &t) {
        int n = s.size();
        int l = 0, r = n - 1, k = t.size(), ans = n;
        while (l <= r) {
            int mid = l + r >> 1;
            if (s.substr(SA[mid], min(n - SA[mid], k)) > t) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        return ans;
    }

    void print_suffix(){
        cout<< "Suffixes :\n" ;
        for(int i=0; i<SA.size(); i++)
            cout<< SA[i] << " " << str.substr(SA[i], n-SA[i]) << "\n" ;
    }
 
    void print_lcp(){
        cout<< "LCP :\n" ;
        for(int i=0; i<lcp.size(); i++)
            cout<< lcp[i] << "\n" ;
    }
}



void solve()
{
    string s,ss;
    cin >> s >> ss;
    int len1 = s.size();
    int len2 = ss.size();
    if(len2 > len1)
    {
        cout << 0 << endl;
        return;
    }
    suff::init(s);
    suff::build_lcp();
    suff::build();
    cout << suff::upper_bound(s,ss) -  suff::lower_bound(s,ss) << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>> t;
    for(int i = 1;i <= t;i++){
        cout << "Case " << i << ": "; 
        solve();
    }
  return 0;
}

/*
    This template is for this problem:
    https://codeforces.com/edu/course/2/lesson/2/5/practice/contest/269656/problem/C
*/