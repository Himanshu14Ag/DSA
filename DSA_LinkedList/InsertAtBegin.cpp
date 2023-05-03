#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int x){
       this->data = x;
       this->next = NULL;
    }

};

Node *InsertBegin(Node *head , int x){
    Node* temp = new Node(x);
    temp->next = head;
    return temp;
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
    head = InsertBegin(head,20);
    head = InsertBegin(head,30);
    head = InsertBegin(head,40); 

    Print(head);

    return 0;
}