
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int d){
        this->data = d;
        this->next = NULL;        
    }
};

// Naive Solution ---------------------------------
Node *DeleteHead(Node *head){
    if(head==NULL)
        return NULL;

    if(head->next == NULL){
        delete head;
        return NULL;
    }

    Node *curr = head;
    while(curr->next!=head){
        curr = curr->next;
    }
    curr->next = head->next;
    delete head;
    return (curr->next);
}

// Efficient Solution -------------------------
Node *Delete(Node *head){
    if(head == NULL)
        return NULL;
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    
    head->data = head->next->data;
    Node *temp = head->next;
    head->next = head->next->next;
    delete temp;
    return head;
}

// Print Function ----------------------
void print(Node *head){
    if(head==NULL)
        return;

    cout<<head->data<<" ";
    
    for(Node *p = head->next; p!=head; p=p->next)
        cout<<p->data<<" ";
}


int main(){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = head;
    print(head);
    cout<<endl;
    head = DeleteHead(head);
    print(head);
    cout<<endl;
    head = Delete(head);
    print(head);
}

