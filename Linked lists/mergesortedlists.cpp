#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* next;
};

node* getnode(int data){
    node* newnode=new node;
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

node* insert(node* root,int data){
    if(root==NULL)
        return getnode(data);

    node* temp=root;
    while(temp->next!=NULL){

        temp=temp->next;
    }
    temp->next=getnode(data);

    return root;
}

node* merge(node* root,node* root2){
    if(root==NULL && root2==NULL)
        return NULL;
    if(root==NULL)
        return root2;
    if(root2==NULL)
        return root;


    node* ans=getnode(-1);
    if(root->data < root2->data){
        root->next=merge(root->next,root2);
        ans->next=root;
    }
    else{
        root2->next=merge(root,root2->next);
        ans->next=root2;
    }

    return ans->next;
}


void print(node* root){
    if(root==NULL)
        return ;

    cout<<root->data;
    print(root->next);
}


int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
#endif

    node* root=NULL;
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,3);
    root=insert(root,4);
    root=insert(root,5);

    node* root2=NULL;
    root2=insert(root2,0);
    root2=insert(root2,2);
    root2=insert(root2,3);
    root2=insert(root2,4);
    root2=insert(root2,5);

    root=merge(root,root2);
    
    print(root);

}