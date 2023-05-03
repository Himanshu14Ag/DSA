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


int Floor(node* root , int x){
    node *res = NULL;
    while(root != NULL){
        if(root->key == x)
            return root->key;

        else if(root->key > x)
            root->left;
            
        else{
            res = root;
            root = root->right;
        }
    }
    return res->key;
}


int main(){
    node* root = new node(50);
    root->left = new node(30);
    root->left->left = new node(10);
    root->left->right = new node(40);
    root->right = new node(70);
    root->right->left = new node(60);
    root->right->right = new node(80);
    
    cout<<"Floor : "<<Floor(root,30);
}

