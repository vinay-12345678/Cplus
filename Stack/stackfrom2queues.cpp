#include <iostream>
#include <queue>
using namespace std;

class stack{
  queue <int> q1,q2;

private:
  void transfer(queue <int> &q1,queue <int> &q2){
    while(!q1.empty()){
      q2.push(q1.front());
      q1.pop();
    }
  }


public:
  void push(int n){
    if(q1.empty()){
      q1.push(n);
    }
    else{
      transfer(q1,q2);
      q1.push(n);
      transfer(q2,q1);
    }
  }


  int top(){
    return q1.front();
  }

  void pop(){
    if(!q1.empty())
      q1.pop();
  }

  int size(){
    return q1.size();
  }

  int empty(){
    return q1.empty();
  }

};

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    

#endif
  
  stack s;
  for(int i=1;i<5;i++){
    s.push(i);
  }
  while(!s.empty()){
    cout<<s.top();
    s.pop();
  }
}


