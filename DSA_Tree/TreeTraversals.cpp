
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


// inorder traversal

void printIn(node *root){       
    if(root!=NULL){
        printIn(root->left);
        cout<<root->key<<" ";
        printIn(root->right);
    }
}

// preorder traversal

void printPre(node *root){       
    if(root!=NULL){
        cout<<root->key<<" ";
        printPre(root->left);
        printPre(root->right);
    }
}

// post order traversal

void printPost(node *root){       
    if(root!=NULL){
        printPost(root->left);
        printPost(root->right);
        cout<<root->key<<" ";
    }
}


// Main code --------------------------

int main(){
    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->right->left = new node(40);
    root->right->right = new node(50);
      
    printIn(root);
    cout<<endl;
    printPre(root);
    cout<<endl;
    printPost(root);
}