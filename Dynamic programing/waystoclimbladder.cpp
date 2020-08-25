#include <bits/stdc++.h>
using namespace std;

vector <int> dp(1000,-1);

int jumps(int e,int s,int j){
    if(s>e)
        return 0;
    if(s==e)
        return 1;
    if(dp[s]!=-1)
        return dp[s];

    int ans=0;
    for(int i=1;i<=j;i++){
        cout<<ans<<endl;
        int a=jumps(e,s+i,j);
        ans+=a;
    }
    return dp[s]=ans;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

    int n=4;

    cout<<jumps(n,1,3);

}