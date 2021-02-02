#include <bits/stdc++.h>
using namespace std;

void find(string s,int i,unordered_map <string,int> m,vector <string> v){
  if(i==s.length()){
    for(auto p:v){
      cout<<p<<" ";
    }
    cout<<endl;
    return;
  }
  if(i>s.length())
    return;

  for(int j=1;j<=s.size();j++){
    if(m.count(s.substr(i,j))!=0){
      v.push_back(s.substr(i,j));
      find(s,i+j,m,v);
      v.pop_back();
    }

  }
  return;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

    int n;
    cin>>n;

    unordered_map <string,int> m;

    string s;

    while(n--){
      cin>>s;
      m[s]++;
    }

    cin>>s; 
    vector <string> v;
    find(s,0,m,v);

}


