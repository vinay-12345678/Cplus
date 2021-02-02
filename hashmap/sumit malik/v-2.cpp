#include <bits/stdc++.h>
using namespace std;

vector <string> find(vector <vector <string> >v){
    unordered_map <string,bool> m;
    unordered_map <string,string> mp;
    for(auto i:v){
        mp[i[0]]=i[1];

        if(m.count(i[0])){
            m[i[0]]=0;
        }
        else
            m[i[0]]=1;

        m[i[1]]=0;
    }
    string start;
    for(auto i:m){
        if(i.second==1)
            start=i.first;
    }

    vector <string> ans;
    ans.push_back(start);
    while(mp.count(start)){
        ans.push_back(mp[start]);
        start=mp[start];
    }

    return ans;

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

    int n;
    cin>>n;
    vector <vector <string> >arr;
    vector <string> ans;
    while(n--){
        string s;
        vector <string> v;
        cin>>s;
        v.push_back(s);
        cin>>s;
        v.push_back(s);
        arr.push_back(v);
    }

    ans=find(arr);
    for(int i=0;i<ans.size();i++){
        if(i==ans.size()-1)
            cout<<ans[i]<<endl;
        else
            cout<<ans[i]<<"->";

    }

}