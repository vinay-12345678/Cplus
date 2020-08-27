#include <bits/stdc++.h>
using namespace std;

struct node
{
    node* left;
    int data;
    node* right;
};

node* getnode(int data){
    node* newnode=new node;
    newnode->left=NULL;
    newnode->data=data;
    newnode->right=NULL;
    return newnode;
}

node* buildtree(node* root,int data){
    if(root==NULL)
        return getnode(data);

    if(data < root->data){
        root->left=buildtree(root->left,data);
    }
    else{
        root->right=buildtree(root->right,data);
    }

    return root;
}

node* del(node* root,int data){

    if(root->data==data){
        if(root->left == NULL && root->right == NULL){
            delete(root);
            return NULL;
        }
        else if(root->left == NULL){
            node* temp=root->right;
            delete(root);
            return temp;
        }
        else if(root->right == NULL){
            node* temp=root->left;
            delete(root);
            return temp;
        }
        else{
            node* last=root->right;

            while(last->left!=NULL){
                last=last->left;
            }

            root->data=last->data;
            root->right=del(root->right,last->data);

            return root;
        }

    }
    else if(data < root->data){
        root->left=del(root->left,data);
    }
    else{
        root->right=del(root->right,data);
    }

    return root;
}

void print(node* root){
    if(root==NULL)
        return;

    print(root->left);
    cout<<root->data;
    print(root->right);

    return;
}


int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

    node* root=NULL;
    root=buildtree(root,4);
    root=buildtree(root,2);
    root=buildtree(root,1);
    root=buildtree(root,3);
    root=buildtree(root,5);
    root=buildtree(root,7);
    root=buildtree(root,6);
    root=buildtree(root,9);
    root=buildtree(root,8);
    print(root);
    cout<<endl;

    root=del(root,5);
    print(root);
}