#include <bits/stdc++.h>
using namespace std;

int find(vector <int> v){
    vector <int> one(v.size());
    vector <int> zero(v.size());

    unordered_map <int,int> m;
    int count=0;

    for(int i=0;i<v.size();i++){
        if(i==0){
            if(v[i]==1){
                one[i]=1;
                zero[i]=0;
            }
            else{
                one[i]=0;
                zero[i]=1;   
            }
        }
        else{
            if(v[i]==1){
                one[i]=1+one[i-1];
                zero[i]=zero[i-1];
            }
            else{
                one[i]=one[i-1];
                zero[i]=1+zero[i-1];   
            }
        }

        if(one[i]==zero[i])
            count++;
        if(m.count(one[i]-zero[i]))
            count+=m[one[i]-zero[i]];

        m[one[i]-zero[i]]++;
    }

    return count;

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout);
    
#endif

    int n;
    cin>>n;

    vector <int> v(n);

    for(int i=0;i<n;i++)
        cin>>v[i];


    cout<<find(v);
    
}