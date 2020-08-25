#include <bits/stdc++.h>
using namespace std;

vector <vector <int> > dp(100,vector <int> (100,-1));

int wine(vector <int> v,int year,int i,int j){
    if(i>j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];

    int a=v[i]*year + wine(v,year+1,i+1,j);
    int b=v[j]*year + wine(v,year+1,i,j-1);

    return dp[i][j]=max(a,b);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

    vector <int> v={2,3,5,1,4};

    cout<<wine(v,1,0,v.size()-1);

}