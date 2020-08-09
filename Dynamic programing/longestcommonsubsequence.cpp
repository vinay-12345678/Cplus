#include <bits/stdc++.h>
using namespace std;

vector <vector<string> >dp(100,vector<string> (100,""));

string find(string s,string st,int i,int j){

  if(i==0 || j==0)
    return "";
  
  if(dp[i-1][j-1]!="")
    return dp[i-1][j-1];

  // cout<<i<<endl;

  if(s[i-1]==st[j-1]){
    return dp[i-1][j-1]=find(s,st,i-1,j-1)+s[i-1];
  }
  else{
    string a=find(s,st,i-1,j);
    string b=find(s,st,i,j-1);
    if(a.length()>b.length())
      return dp[i-1][j-1]=a;

    return dp[i-1][j-1]=b;
  }
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

  string s="abcde",st="afced";

  cout<<find(s,st,s.length(),st.length());
}

