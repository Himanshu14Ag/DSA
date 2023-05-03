
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

node *Insert(node* root, int x){
    if(root==NULL)
        return new node(x);

    else if(root->key<x)
        root->right = Insert(root->right,x);

    else if(root->key>x)
        root->left = Insert(root->left,x);

    return root;
}

void print(node *root){       // inorder traversal
    if(root!=NULL){
        print(root->left);
        cout<<root->key<<" ";
        print(root->right);
    }
}

// Iterative --------------------------

node *InsertBST(node* root,int y){
    node* curr = root;
    node* temp = new node(y);
    node* parent = NULL;

    while(curr!=NULL){
        parent = curr;
        if(curr->key>y)
            curr = curr->left;
        else if(curr->key<y)
            curr = curr->right;
        else
            return root;
    }
    if(parent == NULL)
        return temp;
    else if(parent->key>y)
        parent->left = temp;
    else
        parent->right = temp;

    return root;
}


int main(){
    node* root = new node(50);
    root->left = new node(30);
    root->left->left = new node(10);
    root->left->right = new node(40);
    root->right = new node(70);
    root->right->left = new node(60);
    root->right->right = new node(80);
    int x = 20;
    int y = 90;
    Insert(root,x);
    print(root);
    cout<<endl;
    InsertBST(root,y);
    print(root);
}
