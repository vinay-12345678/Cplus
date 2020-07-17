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

/*node* insert(int data,node* root){
    if(root==NULL)
        return getnode(data);

    if(data<root->data){
        root->left=insert(data,root->left);
    }
    else{
        root->right=insert(data,root->right); 
    }
    return root;
}

void inorder(node* root){
    stack <node* > s;
    node* curr=root;
    while(1){
        if(curr!=NULL){
            s.push(curr);
            cout<<curr->data<<endl;
            curr=curr->left;
        }
        else if(!s.empty()){
            node* curr=s.top();
            s.pop();
            cout<<curr->data;
            curr=curr->right;
        }
        else{

            break;
        }
    }
}*/

node* insert(int data,node* root){
    if(root==NULL)
        return getnode(data);

    root->next=insert(data,root->next);

    return root;
}

node* swap(node* root){
    if(root==NULL)
        return NULL;
    if(root->next==NULL)
        return root;

    node* temp=root->next;
    root->next=swap(temp->next);
    temp->next=root;
    return temp;
}

void print(node* root){
    if(root==NULL){
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
    cout<<endl;
    /*print(root);
    cout<<endl;*/
    root=swap(root);
    print(root);

}

