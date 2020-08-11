#include <bits/stdc++.h>
using namespace std;

vector <vector <int> > dp(100,vector <int> (100,-1));

int find(vector <int> coins,int i,int sum){

  if(sum==0)
    return 1;
  if(i==0)
    return 0;
  if(dp[i][sum]!=-1)
    return dp[i][sum];

  if(coins[i-1]<=sum){
    int a=find(coins,i,sum-coins[i-1]);
    int b=find(coins,i-1,sum);

    return dp[i][sum]=a+b;
  }
  else
    return dp[i][sum]=find(coins,i-1,sum);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif
    vector <int> coins={1,2,3,5};

    cout<<find(coins,coins.size(),10)<<endl;
    /*for(auto i:dp){
      for(auto j:i)
        cout<<j;
      cout<<endl;
    }*/
}

