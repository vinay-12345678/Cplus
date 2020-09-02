#include <bits/stdc++.h>
using namespace std;

void rotate(vector <vector <int> >&v){
    int n=v.size();
    for(int i=0;i<n;i++){
        for(int j=i;j<v.size();j++){
            swap(v[i][j],v[j][i]);
        }
    }

    int i=0,j=v[0].size()-1;
    while(i<j){
        for(int r=0;r<v.size();r++){
            swap(v[r][i],v[r][j]);
        }
        i++;
        j--;
    }

}

void print(vector <vector <int> >v){
    for(auto i:v){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}


int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

    vector <vector <int> >v{{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    print(v);
    cout<<endl;
    rotate(v);
    print(v);
}
