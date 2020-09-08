#include <bits/stdc++.h>
using namespace std;

int balanced(int i,int o,int c,string s){
  if(i<0 || o<0 || c<0)
    return 0;

  if(i==0 && o==0 && c==0){
    cout<<s<<endl;
    return 1;
  }
  
  if(i>=0){
    int a=balanced(i+1,o-1,c,s+'(');
    int b=balanced(i-1,o,c-1,s+')');

    return a+b;
  }
  else
    return 0;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

    int brackets=3;

    cout<<balanced(0,brackets,brackets,"");
}


