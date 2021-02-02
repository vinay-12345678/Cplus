
#include <bits/stdc++.h>
using namespace std;

int find(string s,int i,int j,int &ans){
    if(i==j){
        if(s[i]=='T')
            return 1;
        else
            return 0;
    }

    if(i>j)
        return 0;

    for(int k=i+1;k<j;k++){
        if(s[k]=='^'){
            int a=find(s,i,k-1,ans1);
            int b=find(s,k+1,j,ans1);

            if(a^b == 1){
                ans++;                
            }

        }
        else if(s[k]=='|'){
            int a=find(s,i,k-1,ans1);
            int b=find(s,k+1,j,ans1);

            if(a|b == 1){
                ans++;                
            }

        }
        else if(s[k]=='&'){
            int a=find(s,i,k-1,ans1);
            int b=find(s,k+1,j,ans1);

            if(a&b == 1){
                ans++;                
            }

        }
    }
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

    string s="T|F&T^F";
    int ans=0;
    cout<<find(s,0,s.size()-1,ans)<<endl;
    cout<<ans<<endl;
}