
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


void Preorder(node* root){
    stack<node*> st;
    st.push(root);
    while(st.empty()==false){
        node* curr = st.top();
        cout<<curr->key<<" ";
        st.pop();
        if(curr->right!=NULL)
            st.push(curr->right);
        if(curr->left!=NULL)
            st.push(curr->left);
    }
}


//Optimal Solution ----------------------------------

void PreOrder(node* root){
    if(root==NULL)
        return;
    stack<node*> st;
    node* curr = root;
    while(curr!=NULL || st.empty()==false){
        while(curr!=NULL){
            cout<<curr->key<<" ";
            if(curr->right!=NULL)
                st.push(curr->right);
            curr = curr->left;
        }

        if(st.empty()==false){
            curr = st.top();
            st.pop();
        }
    } 
}



int main(){
    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->right->left = new node(40);
    root->right->right = new node(50);
    Preorder(root);
    cout<<endl;
    PreOrder(root);
}