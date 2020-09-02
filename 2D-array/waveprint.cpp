#include <bits/stdc++.h>
using namespace std;

void wave(vector <vector <int> >v,int &i,int j){
    
    if(i==v.size()){
        i--;
        while(i>=0){
            cout<<v[i][j]<<" ";
            i--;
        }
    }
    else{
        i++;
        while(i<v.size()){
            cout<<v[i][j]<<" ";
            i++;
        }
    }
    cout<<endl;
}


int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

    vector <vector <int> >v{{1,4,7,10},{2,5,8,11},{3,6,9,12}};

    int i=-1;
    for(int j=0;j<v[0].size();j++){
        wave(v,i,j);
    }
}
