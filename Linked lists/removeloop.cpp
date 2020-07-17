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

node* remove(node* root){
    node* slow=root;
    node* fast=root;
    while(slow!=NULL && fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            break;
    }
    int count=1;
    while(fast->next!=slow){
        count++;
        fast=fast->next;
    }
    fast=root;
    while(count--){
        fast=fast->next;
    }
    node* temp=root;
    while(temp!=fast){
        temp=temp->next;
        fast=fast->next;
    }
    while(true){
        if(slow->next==fast){
            slow->next=NULL;
            break;
        }
        slow=slow->next;
    }
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
    root->next->next->next->next=root->next;
    root=remove(root);
    print(root);
}

