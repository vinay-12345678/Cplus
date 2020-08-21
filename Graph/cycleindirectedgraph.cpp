#include <bits/stdc++.h>
using namespace std;

class graph{
  map <int,vector <int> > m;
  int count=0;
public:
  void addedge(int a,int b){
    m[a].push_back(b);
  }

  void __dfs(vector <bool> &visited,int parent,vector <int> &path){

    visited[parent]=1;
    // cout<<parent<<endl;

    path[parent]=1;

    for(auto child:m[parent]){
      if(visited[child]==0){
        __dfs(visited,child,path);
      }
      else if(path[child]==1)
        count++;
    }

    path[parent]=0;
  }

  void dfs(int parent){
    vector <bool> visited(100,0);
    vector <int> path(100,0);
    __dfs(visited,parent,path);
    cout<<count<<endl;

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
    g.addedge(6,5);
    g.addedge(3,2);
    g.addedge(4,3);
    g.addedge(4,6);
    g.addedge(5,4);

    /*g.addedge(7,8);
    g.addedge(7,9);
    g.addedge(9,8);*/
    g.dfs(1);
    // g.bfs(7);
    // cout<<g.dfs(1);
}


