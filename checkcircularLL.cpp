#include<iostream>
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
void print(node *head){
    node *temp = head;
    int len = findlength(head);
    int count = 0 ;
    while(count < len){
        cout<<temp ->data<<" ";
        temp = temp -> next;
    }
}
bool check(node* &head){
    int len = findlength(head);
    int count = 0;
    node* temp = head;
    node* temp2 = head-> next ;
    while(count <= len){
        
        if(temp -> next != temp2)
        return false;
        cout<<"a";
        temp = temp -> next ;
        temp2 = temp2 -> next ;
        count++ ;
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
    node* seventh = new node(70);
    node* eight = new node(80);
    node* ninth = new node(90);


    first -> next = second;
    second -> next = third ;
    third -> next = fourth ;
    fourth -> next = fifth ;
    fifth -> next = sixth ;
    sixth -> next = seventh ;
    seventh -> next = eight;
    eight -> next = ninth ;
    ninth -> next = fifth ;
    
    

    bool a = check(first);
    cout<<a;    

}