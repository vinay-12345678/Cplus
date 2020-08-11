#include <bits/stdc++.h>
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
    if(root==NULL)
        return;

    print(root->left);
    cout<<root->data;
    print(root->right);
}

int sum(node* root,int &res){

    if(root==NULL)
        return 0;

    int l=sum(root->left,res);
    int r=sum(root->right,res);

    int temp=max(l,r)+root->data;
    int ans=max(temp,l+r+root->data);
    res=max(ans,res);

    return temp;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif


    node* root=NULL;
    root=insert(root,4);
    root=insert(root,-2);
    root=insert(root,-5);
    root=insert(root,1);
    root=insert(root,3);
    root=insert(root,5);
    print(root);
    cout<<endl;
    int res=0;
    sum(root,res);
    cout<<res<<endl;
}

