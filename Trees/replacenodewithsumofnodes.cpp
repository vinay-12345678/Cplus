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

int height(node* root){
    if(root==NULL)
        return 0;

    int l=height(root->left);
    int r=height(root->right);

    return max(l,r)+1;
}

int count(node* root,int &sum){
    if(root==NULL)
        return 0;

    int l=count(root->left,sum);
    int r=count(root->right,sum);
    sum+=root->data;

    return 1+l+r;
}

int replace(node* root){
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return root->data;

    int l=replace(root->left);
    int r=replace(root->right);

    int temp=root->data;
    root->data=l+r;
    return temp+root->data;

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
    root=insert(root,4);
    print(root);
    cout<<endl;
    // cout<<height(root);
    // int sum=0;
    // cout<<count(root,sum)<<sum;

    replace(root);
    print(root);
}

