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
bool checkforloop(node* &head){
    if(head == NULL){
        cout<<"LL is empty"<<endl;
        return head;
    }

    node* slow = head;
    node* fast = head;
    while(fast != NULL){
        fast = fast -> next ;
        if(fast != NULL){
            fast = fast -> next ;
            slow = slow ->next ;
        }
        if(slow == fast ){
            return true;
        }
    }
    return false;

}
// finding starting point of loop
node* findstartpoint(node* &head){
    if(head == NULL){
        cout<<"LL is empty"<<endl;
        return NULL;    
    }

    node* slow = head;
    node* fast = head;
    while(fast != NULL){
        fast = fast -> next ;
        if(fast != NULL){
            fast = fast -> next ;
            slow = slow ->next ;
        }
        if(slow == fast ){
            slow = head;
            break;
        }
    }
    while(slow != fast ){
        slow = slow -> next ;
        fast = fast -> next ;

    }

    return slow;

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
    ninth -> next = fifth;

    bool a = checkforloop(first);
    cout<<a<<endl;

    node* temp = findstartpoint(first);
    cout<<temp -> data;

    
}