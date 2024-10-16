#include <bits/stdc++.h>

using namespace std;

//Debug Function-->works for vector,map,set(dbg(stl_name)),,arrar(dbg(array_name,range))
template < typename F, typename S >ostream& operator << ( ostream& os, const pair< F, S > & p ) {return os << "(" << p.first << ", " << p.second << ")";}
template < typename T >ostream &operator << ( ostream & os, const vector< T > &v ) {os << "{";for(auto it = v.begin(); it != v.end(); ++it) {if( it != v.begin() ) os << ", ";os << *it;}return os << "}";}
template < typename T >ostream &operator << ( ostream & os, const set< T > &v ) {os << "[";for(auto it = v.begin(); it != v.end(); ++it) {if( it != v.begin() ) os << ", ";os << *it;}return os << "]";}
template < typename T >ostream &operator << ( ostream & os, const multiset< T > &v ) {os << "[";for(auto it = v.begin(); it != v.end(); ++it) {if( it != v.begin() ) os << ", ";os << *it;}return os << "]";}
template < typename F, typename S >ostream &operator << ( ostream & os, const map< F, S > &v ) {os << "[";for(auto it = v.begin(); it != v.end(); ++it) {if( it != v.begin() ) os << ", ";os << it -> first << " = " << it -> second ;}return os << "]";}
#define dbg(args...) do {cerr << #args << " : "; arif(args); } while(0)
clock_t tStart = clock();
#define timeStamp dbg("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)
void arif () {cerr << endl;}
template <typename T>void arif( T a[], int n ) {for(int i = 0; i < n; ++i) cerr << a[i] << ' ';cerr << endl;}
template <typename T, typename ... hello>void arif( T arg, const hello &... rest) {cerr << arg << ' ';arif(rest...);}

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

struct node {
    bool endmark;//this will tell us ,is there any string which end in this node?
    node* next[26 + 1];//a node can have at most 26 child.
    int totalWord;
    node()
    {
        endmark = false;
        totalWord = 0;
        for (int i = 0; i < 26; i++)//0-a,1-b,2-c.....25-z
            next[i] = NULL;
    }
} * root;

//to insert a string in our trie
bool insert(string str, int len)//TC->sum of length of each inserted string.MC-->sum of length of each inserted string*number of alphabets
{
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)//checking if the node is already existing or not
            curr->next[id] = new node();//create new node
        curr = curr->next[id];//already exist kore
        curr->totalWord++;
        if(curr->endmark)
            return true;
    }
    curr->endmark = 1;
    return curr->totalWord > 1;
}

//searching a string in trie
bool search(string str, int len)//TC-->O(|str|)
{
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            return false;
        curr = curr->next[id];
    }
    return curr->endmark;
}

//multiple test case er jonno node gula must delete kore dite hobe proti testcase er por.else MLE khauar chance thakbe
void del(node* cur)
{
    for (int i = 0; i < 26; i++)
        if (cur->next[i])
            del(cur->next[i]);
    delete (cur);
}

void solve()
{
  /*
    1. Think Greedy
    2. Think Brute Force
    3. Think solution in reverse order
    4. Think DP [ check constraints carefully ]
    5. Check base cases for DP and prove solution for Greedy
    6. Think Graph
  */ 
    
    root = new node();//creating root
    int n;
    cin >> n;
    vector<string>vc(n);
    fr(vc)cin >> i;
    fr(vc){
        if(insert(i,i.size()))
        {
            cout << "BAD SET" << endl << i << endl;
            return;
        }
    }
    cout << "GOOD SET" << endl;
    del(root);
}   

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // auto st = clock();
    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    // cerr << 1.0*(clock()-st)/CLOCKS_PER_SEC << endl;
    return 0;
}
/*Problem_link
   https://leetcode.com/problems/search-suggestions-system/description/
   https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/description/
   https://leetcode.com/problems/implement-trie-prefix-tree/description/
   https://leetcode.com/problems/design-add-and-search-words-data-structure/description/
*/