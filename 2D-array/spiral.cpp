#include <bits/stdc++.h>
using namespace std;

void spiral(vector <vector <int> >v){
    int l=0,r=v[0].size()-1,u=0,d=v.size()-1;

    while(l<=r && u<=d){
        for(int i=l;i<=r;i++){
            cout<<v[u][i]<<" ";
        }
        u++;

        for(int i=u;i<=d;i++){
            cout<<v[i][r]<<" ";
        }
        r--;

        for(int i=r;i>=l;i--){
            cout<<v[d][i]<<" ";
        }
        d--;

        for(int i=d;i>=u;i--){
            cout<<v[i][l]<<" ";
        }
        l++;

        cout<<endl;
    }
}


int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

    vector <vector <int> >v{{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20}};

    spiral(v);
}
