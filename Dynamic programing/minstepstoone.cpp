#include <bits/stdc++.h>
using namespace std;

vector <int> dp(10000,-1);

int count(int n){
    if(n==0)
        return 0;
    if(dp[n]!=-1)
        return dp[n];

    int a=INT_MAX,b=INT_MAX,c=INT_MAX;
    if(n%3==0)
        a=1+count(n/3);
    if(n%2==0)
        b=1+count(n/2);
    c=1+count(n-1);

    return dp[n]=min(min(a,b),c);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

    int n=34;

    cout<<count(n);

}