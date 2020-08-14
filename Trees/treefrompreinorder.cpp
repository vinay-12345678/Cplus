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

node* tree(vector <int> pre,vector <int> in,int s,int e){

    if(s>e)
        return NULL;

    static int i=0;

    int index;
    for(int j=s;j<=e;j++){
        if(in[j]==pre[i])
            index=j;
    }

    i++;
    node* newnode=getnode(in[index]);
    newnode->left=tree(pre,in,s,index-1);
    newnode->right=tree(pre,in,index+1,e);
    return newnode;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif



    vector <int> pre={1,2,3,4,8,5,6,7};
    vector <int> in={3,2,8,4,1,6,7,5};
    node* root=NULL;
    root=tree(pre,in,0,in.size()-1);
    print(root);
}

