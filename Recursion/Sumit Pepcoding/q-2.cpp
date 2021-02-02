#include <bits/stdc++.h>
using namespace std;

bool canplace(vector <vector <int> >v,int r,int c,vector <int> row,vector <int> col,vector <int> rdig,vector <int> ldig){
  if(row[r]==0 && col[c]==0 && ldig[r+c]==0 && rdig[r-c+v.size()-1]==0)
    return 1;
  return 0;
}

bool queen(vector <vector <int> >&v,int r,vector <int> &row,vector <int> &col,vector <int> &rdig,vector <int> &ldig){
  if(r>=v.size()){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v.size();j++){
            if(v[i][j]==1){
              cout<<i<<"-"<<j<<",";
            }
        }
    }
    cout<<endl;
    return 1;
  }

  for(int c=0;c<v.size();c++){
    if(canplace(v,r,c,row,col,rdig,ldig)){
      v[r][c]=1;
      row[r]=1;
      col[c]=1;
      ldig[r+c]=1;
      rdig[r-c+v.size()-1]=1;
      // if(queen(v,r+1,row,col,rdig,ldig)){
      //   return 1;
      // }
        queen(v,r+1,row,col,rdig,ldig);
        v[r][c]=0;
        v[r][c]=0;
        row[r]=0;
        col[c]=0;
        ldig[r+c]=0;
        rdig[r-c+v.size()-1]=0;
      
    }
  }

  return 0;


}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

    vector <vector <int> >v(4,vector <int> (4,0));

    vector <int> row(v.size(),0);
    vector <int> col(v.size(),0);
    vector <int> rdig(2*v.size(),0);
    vector <int> ldig(2*v.size(),0);

    queen(v,0,row,col,rdig,ldig);

    

}


