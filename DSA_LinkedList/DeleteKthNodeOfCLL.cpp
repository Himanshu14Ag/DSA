
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

Node *DeleteHead(Node *head){
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



Node *DeleteKthNode(Node *head, int k){
    if(head == NULL)
        return head;
    if(k==1)
        return DeleteHead(head);

    Node *curr = head;
    for(int i=0;i<k-2;i++)
        curr = curr->next;
    
    Node *temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
    return head;
}


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
    head = DeleteKthNode(head,3);
    print(head);
}