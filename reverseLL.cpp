#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(int data){
        this ->data = data ;
        this -> next = NULL;
    }
};
void print(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;

    }
    cout<<endl;
}
// reversing a linked list 
void reverse(node * &prev, node* &curr){
    // base case 
    if(curr == NULL){
        return ;
    }
    // 1 case solve kro baaki recursion sambhal lega 
    node* forward = curr->next;
    curr->next = prev ;

    // recursive call
    reverse(curr, forward);

}
int main(){
    node* first = new node(1);
    node* second = new node(2);
    node* third = new node(3);
    node* fourth = new node(4);
    node* fifth = new node(5);

    first -> next = second;
    second -> next = third ;
    third -> next = fourth ;
    fourth -> next = fifth;
    print(first);

    node * prev = NULL;
    node * curr = first;

    reverse(prev, curr);
    
    print(curr);

}