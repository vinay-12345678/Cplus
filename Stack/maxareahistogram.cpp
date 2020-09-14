#include <bits/stdc++.h>
using namespace std;

void ngl(vector <int> v,vector <int> &left){
  stack <pair<int,int> > s;
  s.push(make_pair(v[0],0));

  left.push_back(0);

  for(int i=1;i<v.size();i++){
    while(!s.empty()){
      int top=s.top().first;
      if(top>=v[i])
        s.pop();
      else
        break;
    }
    if(s.empty()){
      left.push_back(i);
    }
    else
      left.push_back(i-s.top().second-1);


    s.push(make_pair(v[i],i));
  }

}

void ngr(vector <int> v,vector <int> &right){
  stack <pair<int,int> > s;
  int n=v.size()-1;
  s.push(make_pair(v[n],n));

  right.insert(right.begin(),0);

  for(int i=n-1;i>=0;i--){
    while(!s.empty()){
      int top=s.top().first;
      if(top>=v[i])
        s.pop();
      else
        break;
    }
    if(s.empty()){
      right.insert(right.begin(),n-i);
    }
    else
      right.insert(right.begin(),s.top().second-i-1);


    s.push(make_pair(v[i],i));
  }

}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

    vector <int> v={6,2,5,4,5,1,6};

    vector <int> left,right;

    ngl(v,left);
    ngr(v,right);

    int maxi=INT_MIN;
    for(int i=0;i<v.size();i++){
      maxi=max(maxi,(left[i]+right[i]+1)*v[i]);
    }
    cout<<maxi<<endl;


}


