#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int data){
        this -> data = data;
        this -> next = NULL;

    }
};
void print(node* head){
    node* temp = head ;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp -> next;
    }
}
// remove dupllicates element in LL
void removeDuplicates(node* &head){
    if(head == NULL){
        cout<<"LL is empty"<<endl;
        return ;
    }
    if(head -> next == NULL){
        return ;
    }
    node* curr = head ;
    while(curr != NULL){
        if((curr->next != NULL) && curr -> data == curr->next-> data){
            curr -> next = curr -> next -> next;
        }
        else
        curr = curr -> next ;
    }

}
void insertathead(node* &head, int data){
    if(head == NULL){
        node * temp = new node(data);
        temp -> next = head;
        
    }
    node * temp = head;

}
int main(){
    node* first = new node(1);
    node* second = new node(2);
    node* third = new node(2);
    node* fourth = new node(3);
    node* fifth = new node(4);
    node* sixth = new node(4);

    first -> next = second;
    second ->next = third;
    third -> next = fourth;
    fourth -> next = fifth ;
    fifth ->next = sixth ;
    print(first);

    cout<<"final ans is: ";
    removeDuplicates(first);
    print(first);
}