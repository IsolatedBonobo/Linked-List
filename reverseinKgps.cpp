#include<iostream>
using namespace std;
class node{
    public:
    int data ;
    node* next ;
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
// reverse LL in gp of k no of nodes 
node* reverseinK(node* &head, int k){
    if(head == NULL){
        cout<<"LL is empty";
        return head ;
    }
    int len = findlength(head);
    if(k > len){
        int count = 0;
        node* prev = NULL;
        node* curr = head ;
        node* right ;
        
        while(count < len){
            right = curr -> next ;
            curr -> next = prev ;
            prev = curr ;
            curr = right ;
            count ++;
            
        }
        return prev;
    }

    int count = 0;
    node* prev = NULL;
    node* curr = head ;
    node* right ;
    
    while(count < k){
        right = curr -> next ;
        curr -> next = prev ;
        prev = curr ;
        curr = right ;
        count ++;
        
    }
    if(right != NULL){
        head -> next = reverseinK(right, k);
    }
    return prev;
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
    cout<<endl;
    node* head = reverseinK(first, 3);
    print(head);


}