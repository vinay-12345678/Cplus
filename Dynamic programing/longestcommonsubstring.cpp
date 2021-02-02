#include <bits/stdc++.h>
using namespace std;

void find(string res,string s1,string s2,int i,int j,string& ans){
  if(i==0 || j==0)
    return;

  if(s1[i-1]==s2[j-1]){
    string a=s1[i-1]+res;

    if(a.length()>ans.length())
      ans=a;
    find(res+s1[i-1],s1,s2,i-1,j-1,ans);
  }
  else{
    find("",s1,s2,i-1,j,ans);
    find("",s1,s2,i,j-1,ans);
  }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

    string s1="abcdgh",s2="abedghr";

    string ans="";
    find("",s1,s2,s1.length(),s2.length(),ans);
    cout<<ans;

}


