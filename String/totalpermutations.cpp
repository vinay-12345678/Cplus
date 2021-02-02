
#include <bits/stdc++.h>
using namespace std;

void find(string s,vector <int> &v,string st){
    if(st.length()==s.length()){
        cout<<st<<endl;
        return;
    }

    for(int i=0;i<s.length();i++){
        if(v[i]==1){
            continue;
        }

        v[i]=1;
        find(s,v,st+s[i]);
        v[i]=0;
    }
    return;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

    string s="abc",st="";
    vector <int> v(s.length(),0);
    find(s,v,st);

}