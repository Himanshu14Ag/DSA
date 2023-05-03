
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node *Insert(Node* head,int x){
    Node *temp = new Node(x);
    if(head == NULL)
        return temp;
    Node *curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = temp;

    return head;
}

Node *DeleteHead(Node *head){
    if(head == NULL)
        return NULL;
    else{
        Node* temp = head->next;
        delete head;
        return temp;
    }
}

void Print(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}


int main(){
    Node *head = new Node(10);
    head = Insert(head,20);
    head = Insert(head,30);
    head = Insert(head,40);
    head = Insert(head,50);

    head = DeleteHead(head);
    Print(head);
}


