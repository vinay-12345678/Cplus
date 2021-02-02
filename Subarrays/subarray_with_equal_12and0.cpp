#include <bits/stdc++.h>
using namespace std;


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout);
    
#endif

    string s="0102010";
    int one,two,zero,count=0;

    map <string,int> m;

    for(int i=0;i<s.length();i++){
        if(i==0){
            if(s[i]=='0'){
                zero=1;
                one=0;
                two=0;
            }
            else if(s[i]=='1'){
                zero=0;
                one=1;
                two=0;
            }
            else if(s[i]=='2'){
                zero=0;
                one=0;
                two=1;
            }
        }
        else{
            if(s[i]=='0'){
                zero+=1;
            }
            else if(s[i]=='1'){
                one+=1;
            }
            else if(s[i]=='2'){
                two+=1;
            }
        }

        if(one==two && two==zero)
            count++;

        string st=to_string(two-one)+"#"+to_string(two-zero);
        if(m.count(st))
            count+=m[st];

        m[st]++;
    }

    cout<<count<<endl;
    
}