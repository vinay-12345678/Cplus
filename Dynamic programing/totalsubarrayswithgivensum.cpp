#include <bits/stdc++.h>
using namespace std;

int sum(vector <int> v,int k){
    map <int,int> m;
    int curr=0,count=0;

    for(auto i:v){
        curr+=i;
        if(curr==k){            //from start upto i
            count++;
        }
        if(m.find(curr-k)!=m.end()){           //from any element before i, upto i
            count+=m[curr-k];
        }

        m[curr]++;
    }

    return count;

}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

    vector <int> v={3,4,7,2,-3,1,4,2};
    int k=7;

    cout<<sum(v,k);


}