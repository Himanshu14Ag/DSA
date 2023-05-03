
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

Node *Insert(Node* head,int x){
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

int Search(Node *head, int x){
    int pos = 1;
    Node* curr = head;
    while(curr!=NULL){
        if(curr->data == x)
            return pos;
        else{
            pos++;
            curr = curr->next;
        }
    }
    return -1;
}



int main(){
    Node *head = new Node(10);
    head = Insert(head,20);
    head = Insert(head,30);
    head = Insert(head,40);

    int x = Search(head,20);
    cout<<"Element at Position : "<<x;
}
