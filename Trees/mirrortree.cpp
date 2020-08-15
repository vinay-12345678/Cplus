#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

struct node
{
    node* left;
    int data;
    node* right;
};

node* getnode(int data){
    node* newnode=new node;
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

node* insert(node* root,int data){
    if(root==NULL)
        return getnode(data);

    if(data<root->data)
        root->left=insert(root->left,data);
    else
        root->right=insert(root->right,data);

    return root;

}

node* mirror(node* root){
    if(root==NULL)
        return root;

    root->left=mirror(root->left);
    root->right=mirror(root->right);

    node* temp=root->right;
    root->right=root->left;
    root->left=temp;

    return root;
}

void printin(node* root){
    stack <node* > s;
    node* curr=root;
    while(true){
        if(curr!=NULL){
            s.push(curr);
            curr=curr->left;
        }
        else if(!s.empty()){
            cout<<s.top()->data;
            curr=s.top()->right;
            s.pop();
        }
        else
            break;

    }
}

void printpre(node* root){

    stack <node* > s;
    node* curr=root;
    while(true){
        if(curr!=NULL){
            cout<<curr->data;
            s.push(curr->right);
            curr=curr->left;
        }
        else if(!s.empty()){
            curr=s.top();
            s.pop();

        }
        else
            break;
    }
}

void printpost(node* root){

    stack <node* > s;
    node* curr=root;
    while(true){
        if(root!=NULL){
            s.push(root);
            root=root->left;
        }
        else if(!s.empty()){
            curr=s.top()->right;
        }
    }
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


    node* root=NULL;
    root=insert(root,4);
    root=insert(root,2);
    root=insert(root,3);
    root=insert(root,1);
    root=insert(root,5);
    root=insert(root,6);
    root=insert(root,7);
    printin(root);
    mirror(root);
    cout<<endl;
    printin(root);
    // cout<<height(root);
    // int sum=0;
    // cout<<count(root,sum)<<sum;
    /*vector <int> pre={1,2,3,4,8,5,6,7};
    vector <int> in={3,2,8,4,1,6,7,5};
    node* root=NULL;
    root=tree(pre,in,0,in.size()-1);
    printin(root);
    cout<<endl;
    printpre(root);*/
}

