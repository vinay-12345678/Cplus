#include <bits/stdc++.h>
using namespace std;

void find(vector <int> v,string s,int n){
  if(s!="" && stoi(s)>n)
    return ;
  if(s!="")
    cout<<s<<endl;

  if(s.size()>=v.size()){
    return;
  }

  for(int i=0;i<v.size();i++){
    if(s=="" && i==0){
      continue;
    }
    string st;
    st+=to_string(v[i]);
    find(v,s+st,n);
  }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif
    int n;
    cin>>n;

    vector <int> v{0,1,2,3,4,5,6,7,8,9};

    find(v,"",n);

}


