#include <bits/stdc++.h>
using namespace std;

void segtree(vector <int> v,vector <int> &arr,int index,int s,int e){

    if(s==e){
        arr[index]=v[s];
        return;
    }
    int mid=(s+e)/2;

    segtree(v,arr,2*index,s,mid);
    segtree(v,arr,2*index+1,mid+1,e);

    arr[index]=arr[2*index]+arr[2*index+1];
}

int find(vector <int> arr,int s,int e,int qs,int qe,int index){

    if(qs>e || qe<s)
        return 0;
    if(qs<=s && qe>=e)
        return arr[index];

    int mid=(s+e)/2;

    int l=find(arr,s,mid,qs,qe,2*index);
    int r=find(arr,mid+1,e,qs,qe,2*index+1);

    return l+r;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif




    vector <int> v={1,2,3,4,5};
    vector <int> arr(2*pow(2,ceil(log2(v.size()))));
    segtree(v,arr,1,0,v.size()-1);

    cout<<find(arr,1,v.size()-1,2,3,1);

    /*int index=1;
    for(auto i:arr){
        cout<<index<<" "<<i<<endl;
        index++;
    }*/
}

