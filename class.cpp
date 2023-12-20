#include<iostream>
using namespace std;
// creating ll
class node{
    public:
    int data;
    node *next;
    node(int data){
        this->data = data ;
        this->next = NULL;

    }
};
// printing ll
void print(node *head){
    node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
// inserting a node on head of ll
void insert(node* &head, int data){
    // step 1
    node* newnode = new node(data);
    // step 2
    newnode->next = head;
    // step3 
    head = newnode;
}
int main(){
    node* first = new node(10);
    // node* second = new node(20);
    // node* third = new node(30);
    // node* fourth = new node(40);
    // node* fifth = new node(50);

    // first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = fifth;
    insert(first, 40);
    insert(first, 30);
    insert(first, 90);

    print(first);


}