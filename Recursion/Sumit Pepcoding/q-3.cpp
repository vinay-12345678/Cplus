#include <bits/stdc++.h>
using namespace std;

int cal(vector <int> score,string s){
  int sum=0;
  for(auto i:s){
    sum+=score[i-'a'];
  }

  return sum;
}

bool valid(string s,map <char,int> &m){
  for(auto i:s){
    m[i]--;
    if(m[i]<0)
      return 0;
  }
  return 1;
}

int find(vector <string> v,int i,map <char,int> m,vector <int> score){
  if(i<0)
    return 0;

  map <char,int> m2(m);
  if(valid(v[i],m2)){
    int a=cal(score,v[i])+find(v,i-1,m2,score);
    int b=find(v,i-1,m,score);
    return max(a,b);
  }
  else
    return find(v,i-1,m,score);

}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

    int n;
    cin>>n;
    vector <string> v;
    string s;
    while(n--){
      cin>>s;
      v.push_back(s);
    }

    cin>>n;

    char a;
    map <char,int> m;
    while(n--){
      cin>>a;
      m[a]++;
    }

    vector <int> score(27,0);
    for(int i=0;i<26;i++){
      cin>>score[i];
    }

    cout<<find(v,v.size()-1,m,score);

}


