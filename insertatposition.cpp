#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(){
        this->data = 0 ;
        this-> next = NULL;
    }
    node(int data){
        this->data = data;
        this->next = NULL;
    }
};
void inserAtHead(node* &head, node* &tail, int data){
    if(head == NULL){
        node* newnode = new node(data);
        head = newnode;
        tail = newnode;
        return;
    }
    // step 1
    node * newnode = new node(data);
    // step 2
    newnode->next = head;
    // s 3
    head = newnode;

}
void inserAtTail(node* &head, node* &tail, int data){
    if(tail == NULL){
        node* newnode = new node(data);
        head = newnode;
        tail = newnode;
        return;
    }
    // step 1
    node * newnode = new node(data);
    // step 2
    tail->next = newnode;
    // s-3
    tail = newnode;
    
}
void print(node *head){
    node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int findlength(node* head){
    int len = 0 ;
    node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}
void insertAtPosition(node* &head, node* &tail, int position, int data){
    if(head == NULL){
        node * newnode = new node(data);
        head = newnode;
        tail = newnode;
        return;
    }
    // finding length of LL
    int len = findlength(head);
    // if position = 0 that is user insert at head
    if(position == 0){
        inserAtHead(head, tail, data);
        return ;
    }
    // if position is lasst that is insert at last 
    if(position >= len){
        inserAtTail(head, tail, data);
        return ;

    }
    // if position is at middle
    // finding prev and current 
    int i = 1;
    node * prev = head;
    while(i < position ){
        prev = prev->next;
        i++;
    }
    node * curr = prev->next;
    // s-2 
    node* newnode = new node(data);
    // S-3
    newnode->next = curr;
    // S-4
    prev->next = newnode;
}

int main(){
    node* first = new node(10);

    inserAtHead(first, first, 90);
    inserAtTail(first, first, 30);
    inserAtHead(first, first, 40);

    insertAtPosition(first, first, 3, 77);
    print(first);
    
}