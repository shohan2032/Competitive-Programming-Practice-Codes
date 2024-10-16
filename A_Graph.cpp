"": {
  "prefix": "",
  "body": [
    "#include <bits/stdc++.h>",
    "",
    "using namespace std;",
    "",
    "#define db long long",
    "#define ll long long",
    "#define vi vector<int>",
    "#define vs vector<string>",
    "#define vl vector<ll>",
    "#define pii pair<int, int>",
    "#define vpi vector<pair<int, int>>",
    "#define vpl vector<pair<ll, ll>>",
    "#define vpd vector<pair<double, double>>",
    "#define vps vector<pair<string, string>>",
    "#define mp(x, y) make_pair(x, y)",
    "#define f first",
    "#define s second",
    "#define pb(x) push_back(x)",
    "#define pp(x) pop_back(x)",
    "#define fr(cont) for (auto &i : (cont))",
    "#define all(cont) cont.begin(), cont.end()",
    "#define rall(cont) cont.rbegin(), cont.rend()",
    "",
    "const int N = 1e5 + 9;",
    "vi ad_list[N];",
    "bool vis[N];",
    "ll path_no = 1;",
    "ll path[N];//for path between any two vertex",
    "queue<int>q;",
    "",
    "void dfs(int u,ll path_no)//TC-->BigO(v+e).DFS is a recursive travers algorithm for greaph.",
    "{",
    "    vis[u] = true;",
    "    fr(ad_list[u]){",
    "        path[i] = path_no;",
    "        if(!vis[i])",
    "            dfs(i,path_no);",
    "    }",
    "}",
    "void bfs(int u)//TC-->BigO(v+e).DFS is a recursive travers algorithm for greaph.",
    "{",
    "    q.push(u);",
    "    vis[u] = true;",
    "    while(!q.empty())",
    "    {",
    "        u = q.front();",
    "        q.pop();",
    "        fr(ad_list[u])",
    "        {",
    "            if(!vis[i]){",
    "                q.push(i);",
    "                vis[i] = true;",
    "            }",
    "        }",
    "    }",
    "}",
    "void is_conected_graph(int v)//TC-->BigO(v+e)",
    "{",
    "    for(int i = 1;i <= v;i++)",
    "    {",
    "        if(!vis[i])",
    "        {",
    "            cout << \"DISCONNECTED GRAPH\" << endl;",
    "            return;",
    "        }",
    "    }",
    "    cout << \"CONNECTED GRAPH\"<< endl;",
    "    /*  ",
    "        test case for connected and disconnected graph",
    "        4 5",
    "        1 2",
    "        1 3",
    "        2 3",
    "        2 4",
    "        3 4",
    "        CONNECTED GRAPH",
    "",
    "        4 3",
    "        2 3",
    "        2 4",
    "        3 4",
    "        DISCONNECTED GRAPH",
    "    */",
    "}",
    "void connected_component(int v)//TC-->BigO(v+e).",
    "{                           ",
    "    ll connected_com = 0;",
    "    for(int i = 1;i <= v;i++)",
    "    {",
    "        if(!vis[i])",
    "        {",
    "            connected_com++;",
    "            dfs(i,path_no);",
    "            path_no++;",
    "        }",
    "    }",
    "    // cout << \"Total Connected Component is \" << connected_com << endl;",
    "    //with this func i can count total connected component ",
    "    //can detect path for any two two vetex i.e. is there any path between u and v",
    "    /*  ",
    "        test case for is the there any path between u and v ",
    "        6 4",
    "        1 2",
    "        1 3",
    "        3 4",
    "        5 6",
    "        3(query)",
    "        1 5",
    "        5 6",
    "        3 6 ",
    "        TC-->bigO((v+e)+q)-->(v+e)",
    "    */",
    "}",
    "void solve()",
    "{",
    "    int v,e;",
    "    cin>> v >> e;",
    "    while(e--)",
    "    {",
    "        int u,v;",
    "        cin >> u >> v;",
    "        ad_list[u].pb(v);",
    "        ad_list[v].pb(u); ",
    "    }",
    "    // dfs(1);",
    "    // is_conected_graph(v);",
    "    connected_component(v);",
    "    int q;",
    "    cin >> q;",
    "    while(q--)",
    "    {",
    "        int u,v;",
    "        cin >> u >> v;",
    "        if(path[u] == path[v])",
    "            cout << \"Has a path between them\" << endl;",
    "        else",
    "            cout << \"No path between them\" << endl;",
    "    }",
    "    ",
    "}   ",
    "",
    "int main()",
    "{",
    "    ios_base::sync_with_stdio(false);",
    "    cin.tie(NULL);",
    "    cout.tie(NULL);",
    "    // auto st = clock();",
    "    int t = 1;",
    "    // cin >> t;",
    "    while (t--)",
    "        solve();",
    "",
    "    // cerr << 1.0*(clock()-st)/CLOCKS_PER_SEC << endl;",
    "    return 0;",
    "}",
    "/*Problem_link",
    "",
    "*/"
  ],
  "description": ""
}