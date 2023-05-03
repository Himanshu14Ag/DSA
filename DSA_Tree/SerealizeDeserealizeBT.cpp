
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

const int Empty = -1;
int index = 0;

void Serealization(node* root,vector<int> &arr){
    if(root == NULL){
        arr.push_back(Empty);
        return;
    }

    arr.push_back(root->key);
    Serealization(root->left,arr);
    Serealization(root->right,arr);
}

node* Deserealization(vector<int> &arr){
    if(index==arr.size())
        return NULL;
    
    int val = arr[index];
    index++;
    if(val==Empty)
        return NULL;
    
    node* root = new node(val);
    root->left = Deserealization(arr);
    root->right = Deserealization(arr);
    return root;
}

void printIn(node *root){       
    if(root!=NULL){
        printIn(root->left);
        cout<<root->key<<" ";
        printIn(root->right);
    }
}


int main(){
    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->right->left = new node(40);
    root->right->right = new node(50);

    vector<int> arr;
    Serealization(root,arr);
    for(int x:arr)
        cout<<x<<" ";

    cout<<endl;
    Deserealization(arr);
    printIn(root);
}