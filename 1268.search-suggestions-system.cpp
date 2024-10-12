/*
 * @lc app=leetcode id=1268 lang=cpp
 *
 * [1268] Search Suggestions System
 */

// @lc code=start
#define db long long
#define ll long long
// #define int ll
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
    node()
    {
        endmark = false;
        for (int i = 0; i < 26; i++)//0-a,1-b,2-c.....25-z
            next[i] = NULL;//child gulo initially null thakbe
    }
} * root;

//to insert a string in our trie
void insert(string str, int len)//TC->sum of length of each inserted string.MC-->sum of length of each inserted string*number of alphabets
{
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)//checking if the node is already existing or not
            curr->next[id] = new node();//create new node
        curr = curr->next[id];//already exist kore
    }
    curr->endmark = 1;
}
vector<string>ansForCurPre;
void tra(node* cur,string pre)
{
    if(ansForCurPre.size()>=3)
        return;
    if(cur->endmark)
        ansForCurPre.pb(pre);
    for (int i = 0; i < 26; i++)
        if (cur->next[i])
            tra(cur->next[i],pre+(char)(i+'a'));
}

//searching a string in trie
void search(string str, int len)//TC-->O(|str|)
{
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            return;
        curr = curr->next[id];
    }
    tra(curr,str);
}

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& p, string s) {
        
        sort(all(p));
        root = new node();
        fr(p)
            insert(i,i.size());
        string pre;
        vector<vector<string>> ans;
        for(int i = 0;i < s.size();i++)
        {
            pre += s[i];
            search(pre,pre.size());
            ans.pb(ansForCurPre);
            ansForCurPre.clear();
        }
        return ans;
    }
    
};
// @lc code=end

