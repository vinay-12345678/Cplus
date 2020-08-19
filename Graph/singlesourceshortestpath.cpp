#include <bits/stdc++.h>
using namespace std;

class graph{
  // vector <vector < pair<int,int> > >v;
  map <int,vector < pair<int,int> > > m;
  int size;
public:

  // by 2-d vector

  
  /*graph(int n){
    v.resize(n+1);
  }

  void addedge(int a,int b,int dis){
    v[a].push_back(make_pair(b,dis));
    v[b].push_back(make_pair(a,dis));
  }

  void print(){
    for(int i=0;i<v.size();i++){
      cout<<i<<" ";
      for(auto j:v[i])
        cout<<j.first<<j.second<<" ";
      cout<<endl;
    }
  }*/

  graph(int n){
    size=n;
  }

  void addedge(int a,int b,bool bi,int dis){
    if(bi==1){
      m[a].push_back(make_pair(b,dis));
      m[b].push_back(make_pair(a,dis));
    }
    else{
      m[a].push_back(make_pair(b,dis));
    }
  }

  void print(){
    for(auto i:m){
      cout<<i.first<<" ";
      for(auto j:i.second){
        cout<<j.first<<j.second<<" ";
      }
      cout<<endl;
    }
  }

  void bfs(int n){
    queue <int> q;
    vector <bool> v(n+1,0);
    vector <int> dis(n+1,-1);

    q.push(n);
    v[n]=1;
    dis[n]=1;
    while(!q.empty()){
      for(auto i:m[q.front()]){
        if(v[i.first]==0){
          q.push(i.first);
          v[i.first]=1;
          dis[i.first]=dis[q.front()]+1;

        }
      }
      // cout<<q.front();
      q.pop();

    }
    cout<<dis[5]<<endl;
  }

};

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

    graph g(5);
    g.addedge(1,2,1,5);   //(from a,to b,bi directional or not,weight/distance)
    g.addedge(2,3,0,6);
    g.addedge(2,4,1,7);
    g.addedge(3,4,0,8);
    g.addedge(5,1,1,9);

    g.print();

    g.bfs(4);
}


