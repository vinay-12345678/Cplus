#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

struct node{
    node* left;
    int data;
    node* right;
};

node* getnode(int data){
    node* newnode=new node;
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->data=data;
    return newnode;
}

node* insert(node *root,int data){

    if(root==NULL)
        return getnode(data);

    if(data<root->data){
        root->left=insert(root->left,data);
    }
    else{
        root->right=insert(root->right,data);
    }

    return root;
}

void print(node* root){
    if(root==NULL){
        return;
    }

    print(root->left);
    cout<<root->data;
    print(root->right);
}



int hbalance(node* root,bool &ans){
    if(root==NULL){
        ans=ans&1;
        return 0;
    }

    int l=1+hbalance(root->left,ans);
    int r=1+hbalance(root->right,ans);

    if(abs(l-r)<=1){
        ans&=1;
    }
    else
        ans&=0;

    return max(l,r);

}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif


    node* root=NULL;
    root=insert(root,4);
    root=insert(root,2);
    root=insert(root,3);
    root=insert(root,1);
    root=insert(root,5);
    root=insert(root,6);
    root=insert(root,7);
    print(root);
    cout<<endl;
    // cout<<height(root);
    // int sum=0;
    // cout<<count(root,sum)<<sum;
    bool ans=1;
    hbalance(root,ans);
    cout<<ans<<endl;

}

