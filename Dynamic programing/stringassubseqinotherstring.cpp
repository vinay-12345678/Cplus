#include <bits/stdc++.h>
using namespace std;

vector <vector <int> > dp(100,vector <int> (100,-1));

int find(string s,string s1,int i,int j){
    if(j==0)
        return 1;
    if(i==0)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];

    if(s[i-1]==s1[j-1]){
        int a=find(s,s1,i-1,j-1);
        int b=find(s,s1,i-1,j);

        return dp[i][j]=a+b;
    }
    else
        return dp[i][j]=find(s,s1,i-1,j);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

    string s="geeksforgeeks",s1="gks";

    cout<<find(s,s1,s.size(),s1.size());

}