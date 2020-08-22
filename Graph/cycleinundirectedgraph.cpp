#include <bits/stdc++.h>
using namespace std;

class graph{
  map <int,vector <int> >m;
  int count=0;

public:
  void addedge(int a,int b){
    m[a].push_back(b);
    m[b].push_back(a);
  }

  void __dfs(vector <bool> &visited,int parent,int node){
    // cout<<node<<endl;
    visited[parent]=1;

    for(auto child:m[parent]){
      if(visited[child]==0){
        __dfs(visited,child,parent);
      }
      else if(child!=node){
        count++;
      }
    }

  }

  void dfs(int parent){
    vector <bool> visited(100,0);
    visited[parent]=1;

    __dfs(visited,parent,-1);


    count/=2;
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
    g.addedge(5,4);

    /*g.addedge(7,8);
    g.addedge(8,9);
    g.addedge(9,7);*/
    g.dfs(1);

    
}


