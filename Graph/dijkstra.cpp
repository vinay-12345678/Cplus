#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> a,pair<int,int> b){
  return a.second < b.second;
}

class graph{
  map <int,vector < pair<int,int> > > m;

public:
  void addedge(int a,int b,int dis){
    m[a].push_back(make_pair(dis,b));
    m[b].push_back(make_pair(dis,a));
  }

  void dijksta(int p){
    set < pair<int,int> > s;
    map <int,int> dist;
    
    for(auto i : m){
      dist[i.first]=INT_MAX;
    }

    dist[p]=0;
    s.insert(make_pair(0,p));

    while(!s.empty()){
      auto parent=*(s.begin());
      s.erase(s.begin());

      for(auto child:m[parent.second]){
        int dis=parent.first + child.first;
        if(dis<dist[child.second]){

          if(s.find(make_pair(dist[child.second],child.second))!=s.end())
            s.erase(make_pair(dist[child.second],child.second));

          dist[child.second]=dis;
          s.insert(make_pair(dis,child.second));
        }

      }

    }
    for(auto i:dist){
      cout<<i.first<<" "<<i.second<<endl;
    }


  }

};

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

    graph g;
    g.addedge(1,2,1);
    g.addedge(1,3,4);
    g.addedge(2,3,1);
    g.addedge(3,4,2);
    g.addedge(1,4,7);

    g.dijksta(1);
}


