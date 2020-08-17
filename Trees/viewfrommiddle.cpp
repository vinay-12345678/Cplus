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

void viewr(node* root,int l,int &maxi){

    /*queue <node* > q;
    node* prev;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* curr;
        curr=q.front();
        if(curr!=NULL){
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);

            q.pop();
            prev=curr;
        }
        else{
            cout<<prev->data<<endl;
            q.pop();
            if(q.empty())
                break;
            q.push(NULL);
        }
        
    }*/

    if(root==NULL)
        return;

    if(l>maxi){
        cout<<root->data;
        maxi=max(maxi,l);
    }

    viewr(root->right,l+1,maxi);
    viewr(root->left,l+1,maxi);
    return;

}

void viewl(node* root,int l,int &maxi){
    if(root==NULL)
        return;

    if(l>maxi){
        cout<<root->data;
        maxi=max(maxi,l);
    }
    viewl(root->left,l+1,maxi);
    viewl(root->right,l+1,maxi);
    return;
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
    cout<<endl;
    int maxi=0;
    viewr(root->left,1,maxi);
    cout<<endl;
    cout<<root->data<<endl;
    maxi=0;
    viewl(root->right,1,maxi);
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

