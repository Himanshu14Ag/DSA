
#include<bits/stdc++.h>
#include<queue>
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

int MaxWidth(node *root){
    if(root == NULL)
        return 0;
    queue<node*> q;
    q.push(root);
    int res = 0;
    while(q.empty()==false){
        int count = q.size();
        res = max(res,count);
        for(int i=0;i<count;i++){
            node *curr = q.front();
            q.pop();
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right != NULL)
                q.push(curr->right);
        }
    }
    return res;
} 



// Main code --------------------------

int main(){
    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->right->left = new node(40);
    root->right->right = new node(50);
    root->left->left = new node(60);
    root->left->right = new node(70);
      
    cout<<"Max Width : "<<MaxWidth(root);
}