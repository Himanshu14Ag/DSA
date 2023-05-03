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

Node *InsertAtEnd(Node *head, int x){
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

void print(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main(){
    Node *head = new Node(10);
    head = InsertAtEnd(head,20);
    head = InsertAtEnd(head,30);
    head = InsertAtEnd(head,40);

    print(head);
}