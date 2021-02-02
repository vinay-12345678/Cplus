#include <bits/stdc++.h>
using namespace std;

bool find(vector <int> v,int k){
    map <int,int> m;
    for(auto i:v){
        int num=i%k;
        if(m.count(k-num)){
            m.erase(k-num);
        }
        else
            m[num]++;
    }
    if(m.size()==0)
        return 1;
    else
        return 0;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

    int n;
    cin>>n;
    vector <int> v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    int k;
    cin>>k;

    if(find(v,k))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
}