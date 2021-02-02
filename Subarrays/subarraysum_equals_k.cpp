
#include <bits/stdc++.h>
using namespace std;


int subarraySum(vector<int>& nums, int k){

    vector <int> v;
    int sum=0,count=0;
    map <int,int> m;

    for(int i=0;i<nums.size();i++){
        if(i==0){
            sum=nums[i];
        }
        else{
            sum+=nums[i];
        }

        if(sum==k)
            count++;
        if(m.count(sum-k))
            count+=m[sum-k];

        m[sum]++;
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

    int k;
    cin>>k;

    cout<<subarraySum(v,k);
    
}