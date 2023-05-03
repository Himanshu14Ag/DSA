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


// Naive solution -----------------------------

Node *InsertAtBegin(Node *head, int x){
    Node *temp = new Node(x);
    if(head == NULL)
        temp->next = temp;

    else{
        Node *curr = head;
        while(curr->next!=head){
            curr = curr->next;
        }
        curr->next = temp;
        temp->next = head;
    }
    return temp;
} 


// Optimal Solution ------------------------------

Node *InsertOpt(Node *head, int x){
    Node *temp = new Node(x);
    if(head == NULL){
        temp->next = temp;
        return temp;
    }
    else{
        temp->next = head->next;
        head->next = temp;
        int t = temp->data;
        temp->data = head->data;
        head->data = t;
        return head;
    }
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
    head = InsertAtBegin(head,50);
    print(head);
    cout<<endl;
    head = InsertOpt(head,60);
    print(head);
}