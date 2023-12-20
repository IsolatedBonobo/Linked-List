#include<iostream>
using namespace  std;
class node{
    public:
    int data;
    node* prev;
    node* next;
    node(){
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;

    }
};

void print(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int findlength(node*head){
    node*temp = head;
    int len = 0;
    while(temp != NULL){
        temp = temp ->next ;
        len++;
    }
    return len;
}
void insertAtHead(node* &head, node* &tail, int data){
    if(head == NULL){
        node* newnode = new node(data);
        head = newnode;
        tail = newnode;
        return;
    }
    // s-1
    node* newnode = new node(data);
    // s-2
    newnode->next = head;
    // s-3
    head ->prev = newnode;
    // s-4
    head = newnode;
}
void insertAtTail(node* &head, node* &tail, int data){
    if(head == NULL){
        node* newnode = new node(data);
        head = newnode;
        tail = newnode;
        return;
    }
    // s-1 
    node * newnode = new node(data);
    // s-2
    tail->next = newnode; 
    // s-3 
    newnode->prev = tail;
    // s-4
    tail = newnode;


}
void insertAtPosition(node* &head, node* &tail, int data,int position){
    if(head == NULL){
        node* newnode = new node(data);
        head = newnode;
        tail = newnode;
        return;
    }
    if(position == 1){
        insertAtHead(head, tail, data);
        return ;

    }
    int a = findlength(head);
    if(position > a){
        insertAtTail(head, tail, data);
        return;
    }
    node* prevnode = head ;
    int i = 1 ;
    while(i < position - 1){
        prevnode = prevnode->next;
        i++;
    }
    node* curr = prevnode->next;

    node* newnode = new node(data);
    prevnode->next = newnode;
    newnode->prev = prevnode;

    curr->prev = newnode;
    newnode ->next = curr;
}
void deletenode(node* &head, node* &tail, int position){
    
    if(head == NULL){
        cout<<"can't dlete coz node is empty";
        return ;
    }
    if(position == 1){
        node* temp = head;
        head = head ->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return ;
    }
    if(head->next == NULL){
        node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp ;
        
        return;
    }
    if(position > findlength(head)){
        cout<<"pls enter valid index to be deleted";
        return;
    }
    if(position == findlength(head)){
        node* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete temp ;
        return ;
    }
    // delete node from any position 
    int i = 1;
    node* left = head;
    while(i < position -1){
        left = left->next ;
        i++;
    }
    node* curr = left->next;
    node* right = curr->next;
    // s-2
    left ->next = right;
    // s-3 
    right ->prev = left ;
    // s-4
    curr->prev = NULL;
    curr->next = NULL;
    delete curr;
}
int main(){
    node *first = new node(10);
    node *second = new node(20);
    node *third = new node(30);

    first ->next = second;
    second ->next = third;

    third ->prev = second;
    second ->prev = first;

    insertAtHead(first, third, 33);
    insertAtTail(first, third, 66);
    insertAtPosition(first, first, 99, 1);

    print(first);
    cout<<endl;

    deletenode(first, third, 7);
    print(first);
}