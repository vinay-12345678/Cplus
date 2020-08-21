#include <bits/stdc++.h>
using namespace std;

class graph{
  map <int,vector <int> > m;

public:
  void addedge(int a,int b){
    m[a].push_back(b);
    m[b].push_back(a);
  }

  void __dfs(vector <bool> &visited,int start){

    cout<<start<<endl;
    visited[start]=1;

    for(auto child:m[start]){
      if(visited[child]==0){
        __dfs(visited,child);
      }
    }

  }

  void dfs(int start){

    vector <bool> visited(m.size()+1,0);
    __dfs(visited,start);
    
  }


};

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

    graph g;

    g.addedge(1,2);
    g.addedge(2,5);
    g.addedge(5,6);
    g.addedge(2,3);
    g.addedge(3,4);
    g.addedge(4,5);

    g.dfs(1);
}


