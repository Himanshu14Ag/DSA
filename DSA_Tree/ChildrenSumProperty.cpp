

// In this we need to identify if the value hold by root node having leaf,
// is equal to the sum of values of the leaves or not. if yes then print yes otherwise no.


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

bool ChildSum(node *root){
    if(root==NULL) 
        return true;

    if(root->left==NULL && root->right==NULL)
        return true;

    int sum = 0;
    if(root->left!=NULL)
        sum += root->left->key;
    if(root->right!=NULL)
        sum += root->right->key;

    return (root->key == sum && ChildSum(root->left) && ChildSum(root->right));

}

// Main code --------------------------

int main(){
    node *root = new node(20);
    root->left = new node(8);
    root->right = new node(12);
    root->right->left = new node(3);
    root->right->right = new node(9);
      
    int n = ChildSum(root);
    if(n==1)
        cout<<"yes";
    else
        cout<<"no";
}