#include <bits/stdc++.h>
using namespace std;

void phone(vector <string> v,string s,int index,string st){
  int row=s[index]-'0';
  if(index>=s.size()){
    cout<<st<<endl;
    return;
  }

  if(row==0)
    phone(v,s,index+1,st);

  
  int n=v[row].size();
  for(int i=0;i<n;i++){
    st.push_back(v[row][i]);

    phone(v,s,index+1,st);
    st.pop_back();
  }

  return;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

    vector <string> v={"","abc","def","ghi","jkl","mno","pqr","stu","vwx","yz"};
    string s="555",st="";
    phone(v,s,0,st);
    
}

