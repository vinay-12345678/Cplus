#include <bits/stdc++.h>
using namespace std;

class heap{
    vector <int> v;

public:
    heap(int n){
        v.reserve(n);
        v.push_back(-1);
    }

    void push(int n){
        v.push_back(n);

        int i=v.size()-1;
        while(i>1){
            if(v[i]<v[i/2]){
                swap(v[i],v[i/2]);
                i=i/2;
            }
            else
                break;
        }
    }

    void heapify(int i){
        if(i>=v.size())
            return;

        if(i*2 <v.size() && v[i*2]<v[i]){
            swap(v[i],v[i*2]);
            heapify(i*2);
        }
        if((i*2)+1 <v.size() && v[(i*2)+1]<v[i]){
            swap(v[(i*2)+1],v[i]);
            heapify((i*2)+1);
        }
        else
            return;

    }

    void pop(){
        int n=v.size()-1;
        swap(v[1],v[n]);
        v.pop_back();
        heapify(1);
    }

    void print(){
        for(auto i :v){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    bool empty(){
        if(v.size()==1)
            return 1;

        return 0;
    }

    int top(){
        return v[1];
    }

};

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

    heap h(6);

    h.push(10);
    h.push(20);
    h.push(15);
    h.push(14);
    h.push(11);
    h.push(90);
    h.push(4);

    h.print();    

    while(!h.empty()){
        cout<<h.top()<<" ";
        h.pop();
    }
}
