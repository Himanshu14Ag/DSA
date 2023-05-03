
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

// Recursive ------------------

bool Search(node* root, int x){
    if(root == NULL)
        return false;

    else if(root->key == x)
        return true;

    else if(root->key>x)
        return Search(root->left, x);

    else    
        return Search(root->right, x);
}

// Iterative ---------------------

bool SearchBST(node* root, int x){
    while(root!=NULL){
        if(root->key == x)
            return true;

        else if(root->key<x)
            root = root->right;
        
        else
            root = root->left;
    }
    return false;
}


int main(){
    node* root = new node(50);
    root->left = new node(30);
    root->left->left = new node(10);
    root->left->right = new node(40);
    root->right = new node(70);
    root->right->left = new node(60);
    root->right->right = new node(80);
    int x = 40;

    int n = Search(root, x);  
    if(n==0)
        cout<<"False"<<endl;
    else
        cout<<"true"<<endl;

    int m = SearchBST(root, x);  
    if(m==0)
        cout<<"False BST"<<endl;
    else
        cout<<"true BST"<<endl;
    
}
