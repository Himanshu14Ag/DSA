
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

Node *InsertEnd(Node* head,int x){
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

void Print(Node *head){
    Node * temp =  head;
    
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    Node *head = new Node(10);
    head = InsertEnd(head,20);
    head = InsertEnd(head,30);
    head = InsertEnd(head,40);

    Print(head);
}

