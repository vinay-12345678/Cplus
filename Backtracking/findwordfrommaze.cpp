#include <bits/stdc++.h>
using namespace std;

bool find(vector <string> v,vector <vector <int> >&memo,string s,int i,int j,int index,string st){

    if(index>=s.length())
        return 1;
    else 
        if(i<0 || i>=v.size() || j<0 || j>=v.size() || memo[i][j]==1)
        return 0;

    memo[i][j]=1;
    /*for(auto m:memo){
        for(auto n:m){
            cout<<n;
        }
        cout<<endl;
    }*/

    if(v[i][j]==s[index]){
        cout<<st<<endl;
        if(find(v,memo,s,i+1,j,index+1,st+v[i][j]) || find(v,memo,s,i-1,j,index+1,st+v[i][j]) || find(v,memo,s,i,j+1,index+1,st+v[i][j]) || find(v,memo,s,i,j-1,index+1,st+v[i][j])){
            return 1;
        }
        /*else
            return 0;*/
    }
    else{
        cout<<st<<endl;
        if(find(v,memo,s,i+1,j,index,st) || find(v,memo,s,i-1,j,index,st) || find(v,memo,s,i,j+1,index,st) || find(v,memo,s,i,j-1,index,st))
            return 1;
        /*else
            return 0;*/
    }
    memo[i][j]=0;
    return 0;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

    vector <string> v={{'a','b','c'},{'d','e','f'},{'g','h','i'}};
    vector <vector <int> >memo(v.size(),vector <int> (v.size(),0));
    string st="";
    cout<<find(v,memo,"ehi",0,0,0,st);
}

