
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int key;
    node *left;
    node *right;
    node(int d){
        this->key = d;
        this->left = NULL;
        this->right = NULL;
    }
};


node* getSuccessor(node* curr){
    curr = curr->right;
    while(curr!=NULL && curr->left!=NULL){
        curr = curr->left;
    }

    return curr; 
}


node *DeleteBST(node* root , int x){
    if(root==NULL)
        return root;
    
    if(root->key>x)
        root->left = DeleteBST(root->left,x);
    
    else if(root->key<x)
        root->right = DeleteBST(root->right,x);

    else{
        if(root->left==NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }
        else{
            node* succ = getSuccessor(root);
            root->key = succ->key;
            root->right = DeleteBST(root->right,succ->key);
        }
    }
    return root;
}


void print(node *root){       
    if(root!=NULL){
        print(root->left);
        cout<<root->key<<" ";
        print(root->right);
    }
}


int main(){
    node* root = new node(50);
    root->left = new node(30);
    root->left->left = new node(10);
    root->left->right = new node(40);
    root->right = new node(70);
    root->right->left = new node(60);
    root->right->right = new node(80);
    print(root);
    DeleteBST(root,50);
    cout<<"\nAfter Delete: \n";
    print(root);
}
