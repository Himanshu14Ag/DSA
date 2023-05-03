
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

int preIndex = 0;

node* CTree(int in[], int pre[], int start, int end){
    if(start>end)
        return NULL;

    node* root = new node(pre[preIndex++]);
    int inIndex;
    for(int i=start;i<=end;i++){
        if(in[i] == root->key){
            inIndex = i;
            break;
        }
    }
    root->left = CTree(in,pre,start,inIndex-1);
    root->right = CTree(in,pre,inIndex+1,end);

    return root;
}

void print(node *root){       
    if(root!=NULL){
        print(root->left);
        cout<<root->key<<" ";
        print(root->right);
    }
}

int main(){

    int in[] = {20,10,30,40,50};
    int pre[] = {10,20,30,40,50};
    
    node* root = CTree(in,pre,0,4);
    print(root);

}