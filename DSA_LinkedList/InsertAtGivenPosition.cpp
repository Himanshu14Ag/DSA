
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

Node *InsertAtGiven(Node *head, int pos, int data){
    Node *temp = new Node(data);

    if(pos == 1){
        temp->next = head; 
        return temp;
    }
    Node *curr = head;
    for(int i=0; i<=pos-2 && curr!=NULL; i++){
        curr = curr->next;
    }
    if(curr==NULL)
        return head;

    temp->next = curr->next;
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
    head = InsertAtGiven(head,1,20);
    head = InsertAtGiven(head,2,30);
    head = InsertAtGiven(head,3,40);

    Print(head);    
}





