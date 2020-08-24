#include <bits/stdc++.h>
using namespace std;

class dsu{
  vector <int> v;

public:
  dsu(int n){
    v.resize(n+1,-1);
  }

  int find(int n){
    if(v[n]<0)
      return n;

    return find(v[n]);
  }

  int unite(int a,int b){
    int s1=find(a);
    int s2=find(b);

    if(s1!=s2){
      if(v[s1]<v[s2]){
        v[s1]+=v[s2];
        v[s2]=s1;
      }
      else{
        v[s2]+=v[s1];
        v[s1]=s2; 
      }
      return 1;
    }
    return 0;
  }

};

class graph{
  vector < vector <int> >v;

public:
  /*bool compare(vector <int> a,vector <int> b){
    return a[2]>b[2];
  }
*/
  void addedge(int a,int b,int w){
    v.push_back({w,a,b});
  }

  int krushkal(){
    sort(v.begin(),v.end());

    dsu d(v.size());

    int ans=0;
    for(auto i:v){
      if(d.unite(i[1],i[2])){
        
        ans+=i[0];
      }
    }
    return ans;

  }

};

  

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

    graph g;
    g.addedge(1,3,7);
    g.addedge(4,3,2);
    g.addedge(2,4,5);
    g.addedge(1,2,5);
    g.addedge(5,2,6);
    g.addedge(5,7,9);
    g.addedge(8,7,4);
    g.addedge(8,6,8);
    g.addedge(5,6,3);

    cout<<g.krushkal();
}


