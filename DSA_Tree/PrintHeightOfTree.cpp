
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

int Height(node *root){
    if(root==NULL) 
        return 0;

    else 
        return max(Height(root->left),Height(root->right))+1;
}

// Main code --------------------------

int main(){
    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->right->left = new node(40);
    root->right->right = new node(50);
      
    int n = Height(root);
    cout<<n;
}