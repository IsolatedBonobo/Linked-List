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
}
node* reverse(node* &head){

    node* prev = NULL;
    node* curr = head;
    node* forward = curr -> next ;
    while(curr != NULL){
        forward = curr -> next;
        curr-> next = prev ;
        prev = curr ;
        curr = forward;
    }
    
    return prev;
}
node* solve(node* &head1, node* &head2){
    if(head2 == NULL)
    return head1;
    if(head1 == NULL)
    return head2;
    // s - 1
    head1 = reverse(head1);
    head2 = reverse(head2);
    
    // add both LL
    node* anshead = NULL;
    node* anstail = NULL;
    int carry = 0;

    // when we apply addition on both LL
    while(head1 != NULL && head2 != NULL){
        int sum = carry + head1 -> data + head2 -> data;
        int digit = sum % 10 ;
        carry = sum / 10 ;

        // creating a new node to store ans 
        node* newnode = new node(digit);
        if(anshead == NULL){
            anshead = newnode;
            anstail = newnode ;

        }
        else{
            
            anstail -> next = newnode;
            anstail = newnode;
        }
        head1 = head1 -> next;
        head2 = head2 -> next;
    }
    // if head1 is greater than head2
    while(head1 != NULL){
        int sum = carry + head1 -> data;
        int digit = sum %  10;
        carry = sum /10;
        node* newnode = new node(digit);
        anstail -> next = newnode;
        anstail = newnode;
        head1 = head1 -> next;
        
    }
    // if head2 is greater than head1
    while(head2 != NULL){
        int sum = carry + head2 -> data;
        int digit = sum %  10;
        carry = sum /10;
        node* newnode = new node(digit);
        anstail -> next = newnode;
        anstail = newnode;  
        head2 = head2 -> next;
        
    }
    // if carry would not equal to zero
    while(carry != 0){
        int sum = carry ;
        int digit = sum % 10;
        carry = sum /10 ;
        node* newnode = new node(digit);
        anstail -> next = newnode;
        anstail = newnode;  
        
    }


    anshead = reverse(anshead);
    
    return anshead;
}
int main(){
    node* head1 = new node(2);
    node* second1 = new node(4);
    head1 -> next = second1 ;

    node* head2 = new node(9);
    node* one = new node(9);
    node* two = new node(9);
    head2 -> next = one;
    one -> next = two ;


    node* ans = solve(head1, head2);
    print(ans);
}