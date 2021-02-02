#include <bits/stdc++.h>
using namespace std;

void print(string s,map <char,string> m){
  map <char,int> arr;
  for(auto i:s){
    if(arr.count(i)==0){
      cout<<i<<" -> "<<m[i]<<", ";
      arr[i]++;
    }
  }
  cout<<"."<<endl;
}

void find(string s,string st,int i,int j,map <char,string> m){
  if(i>=st.size() && j>=s.size()){
    print(st,m);
    return;
  }
  if(i>=st.size() || j>=s.size())
    return;

  if(m.count(st[i])==0){
    for(int k=1;k<=s.size();k++){
      m[st[i]]=s.substr(j,k);
      find(s,st,i+1,j+k,m);
      m.erase(st[i]);
    }
  }
  else{
    string str=m[st[i]];

    if(s.substr(j,str.length())==str){
      find(s,st,i+1,j+str.length(),m); 
    }
    else
      return;
  }
  return;
}


int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif
    
    string s="mzaddytzaddy",st="abcb";

    map <char,string> m;

    find(s,st,0,0,m);
    
}


