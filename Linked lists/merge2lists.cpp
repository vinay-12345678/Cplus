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

node* merge(node* root1,node* root2){
    node* root;
    root->next=NULL;
    node* ans=root;
    while(root1!=NULL && root2!=NULL){
        if(root1->data < root2->data){
            node* temp=root1;
            root->next=temp;
            root1=root1->next;
            temp->next=NULL;

        }
        else{
            node* temp=root2;
            root->next=temp;
            root2=root2->next;
            temp->next=NULL;   
        }
        root=root->next;

    }
    if(root1!=NULL){
        root->next=root1;
    }
    else if(root2!=NULL){
        root->next=root2;
    }

    return ans->next;
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

    node* root1=NULL;
    node* root2=NULL;
    node* root;
    root1=insert(1,root1);
    root1=insert(2,root1);
    root1=insert(3,root1);
    root1=insert(4,root1);
    root1=insert(5,root1);

    root2=insert(2,root2);
    root2=insert(4,root2);
    root2=insert(5,root2);
    root2=insert(9,root2);
    root=merge(root1,root2);
    print(root);
}

