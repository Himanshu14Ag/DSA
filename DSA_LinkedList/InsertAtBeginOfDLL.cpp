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

Node *InsertAtBegin(Node *head, int x){
    Node *temp = new Node(x);
    temp->next = head;
    if(head!=NULL)
        head->prev = temp;

    return temp;  
}

void print(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main(){
    Node *head = new Node(10);
    head = InsertAtBegin(head,20);
    head = InsertAtBegin(head,30);
    head = InsertAtBegin(head,40);

    print(head);
}