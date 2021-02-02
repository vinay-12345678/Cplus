#include <bits/stdc++.h>
using namespace std;

void find(string s,string st,int i,int one,int num){
  bitset <32> bits(num);

  if(i>=s.size()){
    if(one!=0)
      st.insert(0,to_string(one));
    cout<<st<<endl;
    return;
  }

  if(bits[i]==0){
    if(one!=0){
      st.insert(0,to_string(one));
    }
    find(s,s[s.size()-1-i]+st,i+1,0,num);
  }
  else{
    find(s,st,i+1,one+1,num);
  }


}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

    string s="pep";
    for(int i=0;i<pow(2,s.size());i++)
      find(s,"",0,0,i);

}


