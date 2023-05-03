
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

// Naive Solution

bool isBalanced(node *root){
    if(root==NULL)
        return true;
    int lh = Height(root->left);
    int rh = Height(root->right);
    return(abs(lh-rh)<=1&&isBalanced(root->left)&&isBalanced(root->right));
}

// Optimal Solution

int isBalancedTree(node* root){
    if(root == NULL)
        return 0;
    int lh = isBalancedTree(root->left);
    if(lh==-1)
        return -1;
    int rh = isBalancedTree(root->right);
    if(rh==-1)
        return -1;
    
    if(abs(lh-rh)>1)
        return -1;
    else    
        return max(lh,rh)+1;
}

// Main code --------------------------

int main(){
    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->right->left = new node(40);
    root->right->right = new node(50);
      
    int n = isBalanced(root);
    if(n==0)
        cout<<"False";
    else
        cout<<"true";

    int m = isBalancedTree(root);
    if(m==-1)
        cout<<"\nFalse";
    else    
        cout<<"\nTrue : "<<m;
}