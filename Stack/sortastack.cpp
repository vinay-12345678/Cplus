#include <bits/stdc++.h>
using namespace std;

void insert(stack <int> &s,int n){
  if(s.empty() || s.top()<=n){
    s.push(n);
    return;
  }

  int num=s.top();
  s.pop();
  insert(s,n);
  s.push(num);
}

void sortt(stack <int> &s){
  if(s.empty())
    return;

  int top=s.top();
  s.pop();
  sortt(s);
  insert(s,top);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

    stack <int> s;

    for(int i=5;i>=0;i--){
      s.push(i);
    }

    sortt(s);
    
    while(!s.empty()){
      cout<<s.top();
      s.pop();
    }
}


