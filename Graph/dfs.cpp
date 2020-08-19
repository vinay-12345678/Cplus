#include <bits/stdc++.h>
using namespace std;

class graph{
  map <int,vector <int> >m;
  int size;
public:
  /*graph(int n){
    size=n+1;
  }*/

  void addedge(int a,int b){
    m[a].push_back(b);
    m[b].push_back(a);
  }

  void __dfs(int parent,vector <bool> &v){

    cout<<parent<<endl;
    v[parent]=1;

    for(auto child:m[parent]){
      if(v[child]==0)
        __dfs(child,v);
    }
    return;
  }

  void dfs(){
    int n=m.size();
    vector <bool> v(n,0);

    for(int i=0;i<v.size();i++){
      if(v[i]==0)
        __dfs(i,v);
    }
  }
  

};

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

    graph g;

    g.addedge(0,4);
    g.addedge(0,1);
    g.addedge(0,3);
    g.addedge(2,1);
    g.addedge(2,3);

    g.addedge(6,5);
    g.addedge(6,7);

    g.dfs();
}


