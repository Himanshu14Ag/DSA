
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


//   Method 1 ------------------------------------
void print(Node *head){
    if(head==NULL)
        return;

    cout<<head->data<<" ";
    
    for(Node *p = head->next; p!=head; p=p->next)
        cout<<p->data<<" ";
}

//    Method 2  -------------------------------------
void Print(Node *head){
    if(head==NULL)
        return;

    Node *p = head;
    do{
        cout<<p->data<<" ";
        p = p->next;
    }while(p!=head);
}


int main(){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = head;

    print(head);
    cout<<endl;
    Print(head);
}