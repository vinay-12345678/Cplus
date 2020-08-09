#include <bits/stdc++.h>
using namespace std;

vector <int> dp(100,-1);

/*int rod(vector <int> l,vector <int> p,int rodl){

  if(rodl==0)
    return 0;

  if(dp[rodl]!=-1)
    return dp[rodl];

  int ans=-1;
  for(int i=0;i<l.size();i++){
    if(l[i]<=rodl){
      int sum=p[i]+rod(l,p,rodl-l[i]);
      ans=max(sum,ans);
      dp[rodl]=ans;
    }
  }
  return ans;
}*/


int find(vector <int> v,int sum,int i){

  if(i==0 || sum==0)
    return sum;

  if(dp[i-1]!=-1)
    return dp[i-1];

  cout<<sum<<endl;

  if(2*v[i-1]<=sum){
    int a=find(v,sum-2*v[i-1],i-1);
    int b=find(v,sum,i-1);

    return dp[i-1]=min(a,b);
  }
  else
    return dp[i-1]=find(v,sum,i-1);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif
    vector <int> v={1,6,11,5};

    cout<<find(v,23,v.size());
}

