#include <bits/stdc++.h>
using namespace std;


void find(int &count,string s,string st,vector <int> &v,int i){
  // cout<<st<<endl;

  if(i>=s.length()){
    cout<<count<<"."<<st<<endl;
    count++;
    return;

  }
  if(v[i]==1){
    find(count,s,st,v,i+1);
    return;
  }
  
  v[i]=1;
  find(count,s,st+"("+s[i]+")"+" ",v,i+1);

  for(int j=i+1;j<s.length();j++){
    if(v[j]==0){
      v[j]=1;
      find(count,s,st+"("+s[i]+","+s[j]+")"+" ",v,i+1);
      v[j]=0;
    }
  }
  v[i]=0;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif
    int n;
    cin>>n;

    string s="";
    for(int i=1;i<=n;i++){
      s+=to_string(i);
    }
    int count=1;
    vector <int> v(s.length()+1,0);
    find(count,s,"",v,0);
}


