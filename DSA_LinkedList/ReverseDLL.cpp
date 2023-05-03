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

Node *Reverse(Node *head){
    if(head==NULL || head->next==NULL)
        return head;
    Node *prev = NULL;
    Node *curr = head;

    while(curr != NULL){
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;
        curr = curr->prev;
    }
    return prev->prev;
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

    head = Reverse(head);
    print(head);
}