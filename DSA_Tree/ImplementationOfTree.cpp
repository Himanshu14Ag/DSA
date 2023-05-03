
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

void print(node *root){       // inorder traversal
    if(root!=NULL){
        print(root->left);
        cout<<root->key<<" ";
        print(root->right);
    }
}

int main(){
    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(40);  
    print(root);
}