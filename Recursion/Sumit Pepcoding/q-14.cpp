#include <bits/stdc++.h>
using namespace std;

bool valid(vector <vector <int> >v){
  int sum=-1;
  for(auto r:v){
    int total=0;
    for(auto c:r){
      total+=c;
    }
    if(sum==-1)
      sum=total;
    else if(total!=sum)
      return 0;
  }
  return 1;
}

void find(vector <vector <int> >arr,vector <int> v,int i){
  if(i>=v.size()){
    if(valid(arr)){
      for(auto r:arr){
        cout<<"[";
        for(int c=0;c<r.size();c++){
          if(c!=r.size()-1){
            cout<<r[c]<<",";
          }
          else
            cout<<r[c];
        }
        cout<<"]";
      }
      cout<<endl;
    }
    return;
  }

  for(int j=0;j<arr.size();j++){
    if(j==0){
      arr[j].push_back(v[i]);
      find(arr,v,i+1);
      arr[j].pop_back();
    }
    else if(arr[j-1].size()!=0){
      arr[j].push_back(v[i]);
      find(arr,v,i+1);
      arr[j].pop_back();
    }
  }

  return;
}


int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif
    
    int n;
    cin>>n;

    vector <int> v(n);

    for(int i=0;i<n;i++){
      cin>>v[i];
    }  

    int k;
    cin>>k;

    vector <vector <int> >arr(k);

    find(arr,v,0);
    
}


