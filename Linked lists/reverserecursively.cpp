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

node* reverse(node* root){
    if(root==NULL || root->next==NULL)
        return root;

    node* temp=reverse(root->next);

    node* temp2=temp;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    root->next=NULL;
    temp2->next=root;

    return temp;
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
    root=reverse(root);
    print(root);

}