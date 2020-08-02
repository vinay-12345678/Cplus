#include <bits/stdc++.h>
using namespace std;

int find(vector <int> w,vector <int> v,vector <int> &dp,int weight,int index){

    if(index>=w.size()){
        return 0;
    }
    if(dp[index]!=0)
        return dp[index];

    if(w[index]<=weight){
        int a=v[index]+find(w,v,dp,weight-w[index],index+1);
        int b=find(w,v,dp,weight,index+1);
        return dp[index]=max(a,b);
    }
    else
        return find(w,v,dp,weight,index+1);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

   vector <int> w={2,1,4,3};
   vector <int> v={4,10,2,1};
   vector <int> dp(w.size(),0);
   int weight=6;
   cout<<find(w,v,dp,weight,0);
}

