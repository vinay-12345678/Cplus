#include <bits/stdc++.h>
using namespace std;

vector <int> dp(100,-1);

int find(vector <int> l,vector <int> p,int i,int length){

  if(length==0 || i==0)
    return 0;

  if(dp[i-1]!=-1)
    return dp[i-1];

  cout<<length<<endl;
  if(l[i-1]<=length){
    int a=p[i-1]+find(l,p,i,length-l[i-1]);
    int b=find(l,p,i-1,length);

    return dp[i-1]=max(a,b);
  }
  else
    return dp[i-1]=find(l,p,i-1,length);

}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif
    vector <int> l={1,2,3,4,5,6,7,8};
    vector <int> p={1,5,8,9,10,17,17,20};

    cout<<find(l,p,l.size(),10);
}

