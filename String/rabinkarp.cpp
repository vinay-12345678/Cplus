#include <bits/stdc++.h>
using namespace std;

class hashi{
    map <int,vector <pair<int,int> > >m;

public:
    int ascii(string st,int s,int e){
        int ans=0;
        for(int i=s;i<=e;i++){
            ans+=st[i]-'a';
        }
        return ans;
    }

    void add(string st,int s,int e){
        int key=ascii(st,s,e);
        m[key].push_back(make_pair(s,e));
    }

    int count(int n,string s,string st){
        int ans=0;

        for(auto i:m[n]){
            int m=i.first;
            int n=i.second;
            int j=0;
            while(m<=n){
                if(s[m]!=st[j]){
                    break;
                }
                if(m==n){
                    ans++;
                }
                m++;
                j++;
            }
        }
        return ans;
    }

};

int rabin(string s,string st){
    int n=st.length();
    hashi h;
    for(int i=0;i<=s.length()-st.length();i++){
        h.add(s,i,i+n-1);
    }
    int as=h.ascii(st,0,n-1);

    return h.count(as,s,st);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

    string s="ababdcabdanabdd";
    string st="abd";

    cout<<rabin(s,st);

}