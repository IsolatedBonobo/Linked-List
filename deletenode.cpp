#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data ;
    node* next;
    node(int data){
        this->data = data;
        this->next = NULL;

    }
};
int findlength(node* head){
    int len = 0 ;
    node * temp = head;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}
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
void deletenode(node* &head, node* &tail, int position){
    if(head = NULL){
        cout<<"cannot selete anything bcoz linked list is empty";
        return;
    }
    // if first node to be deleted 
    if(position == 1){
        node* temp = head;
        head = head->next;
        temp -> next = NULL;
        delete temp;
    }
    // if last node to  be deleted 
    int len = findlength(head);
    if(position == len){
        // find previous 
        int i = 1 ;
        node * prev = head;
        while(i < position ){
            prev = prev->next;
            i++;
        }
        // s-2 
        prev->next = NULL;
        // s-3 
        node* temp = tail;
        // s-4
        tail = prev;
        delete temp;

    }
    // if any position to be deletd
    int i = 1;
    node * prev = head;
    while(i<position){
        prev = prev->next;
        i++;
    }
    node* curr = prev->next;
    // s-2
    prev->next = curr->next;
    // s-3
    curr->next = NULL;
    delete curr;

}
void print(node *head){
    node *temp = head;
    while(temp != NULL){
        
        cout<<temp -> data<<" is the data";
        temp = temp->next;
    }
}
int main(){
    cout<<"hello from ashu"<<endl;
    node* first = new node(20);
    node* second = new node(20);
    node* third = new node(30);
    node* fourth = new node(40);
    node* fifth = new node(50);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    print(first);
    deletenode(first, fifth, 1);
    print(first);
    
}