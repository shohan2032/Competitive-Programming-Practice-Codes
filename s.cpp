#include<bits/stdc++.h>
using namespace std;

int main()
{
 
 int t; cin>>t;
 while(t--)
 {
  int n; cin>>n;
  vector<pair<int,int>> p(n);
  for(int i=0;i<n;i++)
   cin>>p[i].first;
  for(int i=0;i<n;i++)
   cin>>p[i].second;

  vector<int> fre(n+1,0);
  map<int,vector<int>> mp;
  for(int i=0;i<n;i++)
  {
   mp[p[i].first].push_back(p[i].second);
   fre[p[i].first]+=p[i].second;
  }
  for(auto it: mp){
   cout<<it.second<<endl;
   sort(it.second.begin(),it.second.end());
   reverse(it.second.begin(),it.second.end());
   cout<<it.second<<endl;
  }

  for(auto it: mp){
   cout<<it.second<<endl;
  }
 }
    
}