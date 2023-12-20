#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next ;
    node(int data){
        this ->data = data ;
        this -> next = NULL;
    }
};
void print(node* head){
    node* temp = head ;
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;

    }
}
int findlength(node* head){
    int len = 0;
    node* temp = head;
    while(temp != NULL){
        len ++;
        temp = temp -> next;

    }
    return len ;
}
node* reverse(node * &head){
    node* prev = NULL;
    node* curr = head;
    node* right = curr -> next;
    while(curr != NULL){
        right = curr -> next;
        curr -> next = prev ;
        curr = right ;
        prev = curr ;
    }
    return prev ;

}
bool checkpallindrome(node* head){
    // step 1 find middlle node
    // and then uske middle node ke ek aage se remaining LL ko reverse kr do 
    node* slow = head;
    node* fast = head;
    while(fast != NULL){
        fast = fast -> next ;
        if(fast != NULL){
            fast = fast -> next ;
            slow = slow -> next ;
        }
    }
    // now slow pointer is on mid 
    node* reverseLLkahead = reverse(slow->next);

    slow -> next = reverseLLkahead;
    // now compairson begin 
    node* temp1 = head;
    node* temp2 = reverseLLkahead;
    while(temp2 != NULL){
        if(temp1 -> data != temp2 -> data)
        return false;

        else{
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
    }
    return true;
}
int main(){
    node* first = new node(10);
    node* second = new node(20);
    node* third = new node(30);
    node* fourth = new node(40);
    node* fifth = new node(50);
    node* sixth = new node(60);

    first -> next = second;
    second -> next = third;
    third -> next = fourth ;
    fourth -> next = fifth ;
    fifth -> next = sixth ;
    

    first = reverse(first);
    print(first);
    

}