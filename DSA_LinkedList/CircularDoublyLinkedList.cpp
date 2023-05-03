
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

// insert a node ------------------------------
Node *InsertNode(Node *head, int x){
    Node *temp = new Node(x);
    if(head == NULL){
        temp->next = temp;
        temp->prev = temp;
        return temp;
    }
    temp->prev = head->prev;
    temp->next = head;
    head->prev->next = temp;
    head->prev = temp;
    return temp;
}


void print(Node *head){
    if(head==NULL)
        return;

    cout<<head->data<<" ";
    
    for(Node *p = head->next; p!=head; p=p->next)
        cout<<p->data<<" ";
}

int main(){
    Node *head = NULL;
    head = InsertNode(head,10);
    head = InsertNode(head,20);
    head = InsertNode(head,30);
    head = InsertNode(head,40);
    print(head);
}