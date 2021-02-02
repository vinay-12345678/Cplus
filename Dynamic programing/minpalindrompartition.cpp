#include <bits/stdc++.h>
using namespace std;

bool palindrome(string s,int i,int j){
  while(i<j){
    if(s[i]!=s[j])
      return 0;
    i++;
    j--;
  }
  return 1;
}

vector <vector <int> > dp(1000,vector <int> (1000,-1));

int find(string s,int i,int j){

  if(i>j)
    return 0;

  if(dp[i][j]!=-1)
    return dp[i][j];

  if(palindrome(s,i,j))
    return 0;

  int ans=INT_MAX;
  for(int k=i;k<=j-1;k++){

    int temp=find(s,i,k)+find(s,k+1,j)+1;

    if(temp<ans)
      ans=temp;
  }
  // cout<<ans<<endl;
  return dp[i][j]=ans;

}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

    string s="nitin";

    cout<<find(s,0,s.size()-1);

}


