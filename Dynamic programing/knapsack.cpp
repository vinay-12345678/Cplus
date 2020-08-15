#include <bits/stdc++.h>
using namespace std;

vector <vector <int> > dp(100,vector <int> (100,-1));

int find(vector <int> w,vector <int> v,int weight,int index){

    if(index<=0){
        return 0;
    }
    if(dp[index][weight]!=-1)
        return dp[index][weight];

    // cout<<weight<<endl;

    if(w[index-1]<=weight){
        int a=v[index-1]+find(w,v,weight-w[index-1],index-1);
        int b=find(w,v,weight,index-1);
        return dp[index][weight]=max(a,b);
    }
    else
        return dp[index][weight]=find(w,v,weight,index-1);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

   vector <int> w={2,1,4,3};
   vector <int> v={4,10,2,1};
   
   int weight=6;
   cout<<find(w,v,weight,w.size());
}

