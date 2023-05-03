

// Whilr uding global variable or pointer always remember not to use namespace because it throws
// ambiguity in your code.

#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;


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

node *prev = NULL;

node* TreeToDLL(node* root){
    
    if(root==NULL)
        return root;
    
    node* head = TreeToDLL(root->left);
    if(prev==NULL)
        head = root;
    else{
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    TreeToDLL(root->right);
    return head;
}


void print(node *head){
    while(head!=NULL){
        cout<<head->key<<" ";
        head = head->right;
    }
}


// Main code --------------------------

int main(){
    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->right->left = new node(40);
    root->right->right = new node(50);
    
    node *head = TreeToDLL(root);
    print(head);
}