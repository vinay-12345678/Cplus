#include <bits/stdc++.h>
using namespace std;

void revrse(stack <int> &s,int a){
  if(s.empty()){
    s.push(a);
    return;
  }

  int b=s.top();
  s.pop();
  revrse(s,a);
  s.push(b);
}

void reverse(stack <int> &s){
  if(s.empty())
    return;

  int a=s.top();
  s.pop();
  reverse(s);
  revrse(s,a);

}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    

#endif
  
  stack <int> s,s1;
  for(int i=1;i<5;i++){
    s.push(i);
  }
  cout<<s.top();
  reverse(s);
  cout<<s.top();
}


