#include <bits/stdc++.h>
using namespace std;

int find(string s){
    map <char,int> m;
    int i=0,j=0,ans=0;

    while(j<s.length()){
        if(m[s[j]]==0){
            m[s[j]]++;
            j++;
            ans=max(ans,j-i);
        }
        else{
            m[s[i]]--;
            i++;
        }

    }

    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

    string s="aabcbcdbca";

    cout<<find(s);
    
}