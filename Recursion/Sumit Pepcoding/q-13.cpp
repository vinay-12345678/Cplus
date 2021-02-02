#include <bits/stdc++.h>
using namespace std;

bool find(string s){
  int i=0,j=s.length()-1;
  while(i<j){
    if(s[i]!=s[j]){
      return 0;
    }
    i++;
    j--;
  }
  return 1;
}


void palin(string s,int i,string st){
  if(i>=s.length()){
    cout<<st<<endl;
    return;
  }
  
  palin(s,i+1,st+"("+s[i]+")");
  for(int j=i+1;j<s.length();j++){
    if(find(s.substr(i,j-i+1))){
      palin(s,j+1,st+"("+s.substr(i,j-i+1)+")");
    }
  }
}


int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif
    
    string s="abaaba";

    palin(s,0,"");    
    
}


