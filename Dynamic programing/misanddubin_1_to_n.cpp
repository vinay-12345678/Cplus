#include <bits/stdc++.h>
using namespace std;

void find(vector <int> v){

  int i=0;
  while(i<v.size()){

    while(1){
      if(v[i]==i+1 || v[v[i]-1]==v[i])
        break;

      else
        swap(v[i],v[v[i]-1]);
    }

    i++;
  }
  
  vector <int> dub,mis;
  for(int i=0;i<v.size();i++){
    if(v[i]!=i+1){
      dub.push_back(v[i]);
      mis.push_back(i+1);
    }
  }

  for(auto i:dub){
    cout<<i;
  }
  cout<<endl;

  for(auto i:mis){
    cout<<i;
  }
  cout<<endl;  
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

    vector <int> v={2,3,1,8,2,3,5,1};

    find(v);

}


