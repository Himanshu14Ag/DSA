
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

Node *DeleteTail(Node *head){
    if(head == NULL)
        return NULL;
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    Node *curr = head;
    while(curr->next->next != NULL){
        curr = curr->next;
    }
    delete(curr->next);
    curr->next = NULL;
    return head;
}

void Print(Node *head){
    Node * temp =  head;
    
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}


int main(){
    Node *head = new Node(10);
    head = Insert(head,20);
    head = Insert(head,30);
    head = Insert(head,40);
    head = Insert(head,50);

    DeleteTail(head);
    DeleteTail(head);
    Print(head);
}


