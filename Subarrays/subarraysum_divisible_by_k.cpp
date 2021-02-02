#include <bits/stdc++.h>
using namespace std;


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout);
    
#endif

    vector <int> v={4,5,0,-2,-3,1};
    int count=0,sum=0,k=5;

    map <int,int> m;

    for(int i=0;i<v.size();i++){
        if(i==0)
            sum=v[i];
        else
            sum+=v[i];

        if(((sum%k)+k)%k==0)
            count++;
        if(m.count(((sum%k)+k)%k))
            count+=m[((sum%k)+k)%k];

        m[((sum%k)+k)%k]++;
    }

    cout<<count<<endl;


    
}