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
void print(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;

    }
}
void sort_method1(node* &head){
    int zero = 0;
    int one = 0;
    int two = 0;
    node* temp = head;
    while(temp != NULL){
        if(temp -> data == 0)
        zero++;
        else if(temp -> data == 1)
        one++;
        else if(temp -> data == 2)
        two++;

    }
    while(zero--){
        temp -> data = 0;
        temp = temp -> next;
    }
    while(one --){
        temp -> data = 1;
        temp = temp -> next;
    }
    while(two--){
        temp -> data = 2;
        temp = temp -> next;
    }

}

node* sort_prettymethod(node* &head){
    if(head == NULL){
        cout<<"LL is empty"<<endl;
        return head;
    }
    if(head -> next == NULL) {
            //sngle node in LL
            return head;
    }
    node* zeroHead = new node(-101);
    node* zeroTail = zeroHead;

    node* oneHead = new node(-101);
    node* oneTail = oneHead;
    
    node* twoHead = new node(-101);
    node* twoTail = twoHead;
    
    node* curr = head;


    // step 1;
    while(curr != NULL){
        // isolating the zero element 
        if(curr -> data == 0){
            node* temp = curr ;
            curr = curr -> next ;
            temp -> next = NULL;

            // now adding it to node of zeroKaHead
            zeroTail-> next = temp;
            zeroTail = temp ;
        }
        else if(curr -> data == 1){
            // isolating all one element 
            node* temp = curr ;
            curr = curr -> next ;
            temp -> next = NULL;

            // now adding it to node of zeroKaHead
            oneTail -> next = temp;
            oneTail = temp;
        }
        else if(curr -> data == 2){
            // isolating all two wali node
            node* temp = curr ;
            curr = curr -> next ;
            temp -> next= NULL;

            // now adding it to node of zeroKaHead
            twoTail-> next = temp;
            twoTail = temp ;
        }
        
    }

    // step 2 deleting dummy nodes of one and two 
    node* temp = oneHead;
    oneHead = oneHead -> next ;
    temp->next = NULL;
    delete temp;

    temp = twoHead;
    twoHead = twoHead -> next ;
    temp -> next= NULL; 
    delete temp ;

    // joining list
    if(oneHead != NULL){
        zeroTail -> next = oneHead;
        if(twoHead != NULL){
            oneTail -> next = twoHead;
        }
 
    }
    else{
        if(twoHead != NULL){
            zeroTail ->next = twoHead;
        }
    }
    
    // remonve zero ka head wala dummy variable
    temp = zeroHead;
    zeroHead = zeroHead -> next;
    temp -> next = NULL; 
    delete temp ;

    return zeroHead;
}
int main(){
    node* head = new node(2);
    node* second = new node(2);
    node* third = new node(2);
    node* fourth = new node(2);
    node* fifth = new node(2);
    node* sixth = new node(1);
    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth -> next = fifth;
    fifth -> next = sixth;

    node* newnode = sort_prettymethod(head);
    
    
    print(newnode);


}