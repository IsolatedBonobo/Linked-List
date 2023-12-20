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
    node * temp = head;
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp ->next ;

    }
}
int findlength(node* head){
    int len = 0;
    node * temp = head;
    while(temp != NULL){
        temp = temp -> next;
        len ++;

    }
    return len ;
}
node* middlenode(node* &head){
    if(head == NULL){
        cout<<"LL is empty";
        return head;
    }
    if(head -> next == NULL){
        return head;
    }
    node* slow = head;
    node* fast = head;
    while( fast != NULL){
        fast = fast -> next ;
        if(fast != NULL){
            fast = fast -> next;
            slow = slow -> next;
        }

    }
    return slow;
}
int main(){
    node* first = new node(10);
    node* second = new node(20);
    node*  third = new node(30);
    node* fourth = new node(40);
    node* fifth = new node(50);

    first -> next = second ;
    second -> next = third ;
    third -> next = fourth ;
    fourth -> next = fifth ;
    fifth -> next = NULL;


    print(first);
    node * a = middlenode(first);
    cout<<endl;
    cout<<a->data;
    
}