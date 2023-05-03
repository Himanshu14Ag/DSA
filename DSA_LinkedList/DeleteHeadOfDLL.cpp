#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    Node *prev;
    Node *next;
    int data;

    Node(int d){
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

Node *Insert(Node *head, int x){
    Node *temp = new Node(x);
    if(head==NULL)
        return temp;

    Node *curr = head;
    while(curr->next!=NULL){
        curr = curr->next;
    }  
    curr->next = temp;
    temp->prev = curr;

    return head;
}

Node *DeleteHead(Node *head){
    if(head == NULL)
        return NULL;
    
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    else{
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
    }
    return head;
}

void print(Node *head){
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

    head = DeleteHead(head);
    print(head);
}