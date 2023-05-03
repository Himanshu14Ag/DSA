
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int d){
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}


Node *DeleteLastNode(Node *head){
    if(head == NULL)
        return NULL;
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    Node *curr = head;
    while(curr->next!=NULL){
        curr = curr->next;
    }
    curr->prev->next = NULL;
    delete curr;

    return head;
}


int main(){
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next  = new Node(40);
    head = DeleteLastNode(head);
    print(head);
}