#include <bits/stdc++.h>
using namespace std;

void middle(stack <int> &s,int mid,int n){

  if(mid==n){
    s.pop();
    return;
  }

  int num=s.top();
  s.pop();
  middle(s,mid,n-1);
  s.push(num);


}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

    stack <int> s;

    for(int i=6;i>=1;i--){
      s.push(i);
    }

    int mid;
    if(s.size()%2==1)
      mid=s.size()/2 + 1;
    else
      mid=s.size()/2;

    middle(s,mid,s.size());

    while(!s.empty()){
      cout<<s.top();
      s.pop();
    }

    
}


