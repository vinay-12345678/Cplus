#include <bits/stdc++.h>
using namespace std;

vector <vector <int> > dp(1000,vector <int> (1000,-1));

int subset(vector <int> v,int sum,int index){
  if(sum==0)
    return 1;
  
  if(index<=0)
    return 0;

  if(dp[index][sum]!=-1)
    return dp[index][sum];

  if(v[index-1]<=sum){
    int a=subset(v,sum-v[index-1],index-1);
    int b=subset(v,sum,index-1);
    return dp[index][sum]=a+b;
  }
  else{
    return dp[index][sum]=subset(v,sum,index-1);
  }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

  vector <int> v={2,3,7,8,10};

  int sum=10;
  cout<<subset(v,sum,v.size());
}

