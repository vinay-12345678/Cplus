#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
};

node* getnode(int data){
    node* newnode= new node;
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

node* insert(int data,node* root){
    if(root==NULL)
        return getnode(data);

    root->next=insert(data,root->next);

    return root;
}

node* rev(node* root){
    node* prev=NULL;
    while(root!=NULL){
        node* temp=root;
        root=root->next;
        temp->next=prev;
        prev=temp;
    }
    return prev;
}

node* add(int c,node* root){
    if(root==NULL && c==0)
        return NULL;
    if(root==NULL)
        return getnode(c);

    int num=root->data;
    root->data=(c+num)%10;
    root->next=add((c+num)/10,root->next);
    return root;
}

void print(node* root){
    if(root==NULL){
        cout<<endl;
        return;
    }

    cout<<root->data;
    print(root->next);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

    node* root=NULL;
    root=insert(1,root);
    root=insert(2,root);
    root=insert(3,root);
    root=insert(4,root);
    root=insert(5,root);
    print(root);
    root=rev(root);
    root=add(4,root);
    root=rev(root);
    print(root);
}

