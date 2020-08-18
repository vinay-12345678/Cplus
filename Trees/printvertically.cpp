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

map <int,vector <int> > m;

void vertical(node* root,int dis){
    if(root==NULL)
        return;

    m[dis].push_back(root->data);

    vertical(root->left,dis-1);
    vertical(root->right,dis+1);
}


int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif


    node* root=NULL;
    root=insert(root,8);
    root=insert(root,6);
    root=insert(root,7);
    root=insert(root,5);
    root=insert(root,3);
    root=insert(root,9);
    root=insert(root,8);
    root=insert(root,10);
    printin(root);
    cout<<endl;
    
    vertical(root,0);

    for(auto i:m){
        int a=i.first;
        cout<<a<<" ";
        for(auto j:m[a]){
            cout<<j;
        }
        cout<<endl;
    }
}

