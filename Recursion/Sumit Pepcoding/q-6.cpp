#include <bits/stdc++.h>
using namespace std;

int gold(vector <vector <int> >&v,int r,int c){
  if(r<0 || c<0 || r>=v.size() || c>=v[0].size())
    return 0;

  if(v[r][c]==0)
    return 0;

  int sum=0;
  sum+=v[r][c];
  v[r][c]=0;

  int a=gold(v,r+1,c);
  int b=gold(v,r-1,c);
  int m=gold(v,r,c+1);
  int d=gold(v,r,c-1);

  return sum+a+b+m+d;

}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif
    int n,m;
    cin>>n>>m;

    vector <vector <int> >v(n,vector <int> (m,0));

    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        cin>>v[i][j];
      }
    }
    int sum=0;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        sum=max(sum,gold(v,i,j));
      }
    }

    cout<<sum<<endl;
    
}


