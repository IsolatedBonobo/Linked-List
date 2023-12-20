#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next ;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
// in this approach i am using address of the common node 
Node* intersection(Node* l1, Node* l2){
    Node* temp2 = l2 ;
    Node* temp1 = l1 ;

    Node* address = temp1 ;
    while(address != NULL){
        Node* mover = temp2 ;
        while(mover != NULL){
            if(address == mover){
                return address  ;
            }
            mover = mover -> next ;
        }
        address = address -> next ;
    }
    return NULL;
}
int len(Node* head){
        int length  = 0;
        Node* temp = head;
        while(temp != NULL){
            length ++ ;
            temp = temp -> next ;
        }
        return length ;
    }
Node* inter(Node* headA, Node* headB){
    Node* first = headA;
    Node* second = headB ;
    int len1 = len(headA);
    int len2 = len(headB);
    int diff = abs(len1 - len2);
    if(len1 > len2){
        int i = 0;
        while(i < diff){
            first = first -> next ;
            i ++;
        }
    }
    else{
        int i = 0 ;
        while(i < diff){
            second = second -> next ;
            i ++;
        }
    }
    

    while(first != NULL){
        
        if(first == second)
            return first ;
        
        first = first -> next ;
        second = second -> next ;
    }
    return NULL;
}
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp -> data <<" ";
        temp = temp -> next ;
    }
    cout<<endl;
}
int main(){
    Node* first = new Node(10);
    Node* second= new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    first -> next = second ;
    second -> next = third ;
    third -> next = fourth ;
    fourth -> next = fifth ;
    
    Node* first2 = new Node(32);
    Node* second2 = new Node(54);
    Node* third2 = new Node(87);

    first2 -> next = second2;
    second2 -> next = third2 ;
    third2 -> next = third ;

    print(first);
    print(first2);
    Node* ans = inter(first, first2);
    if(ans != NULL){
        cout<<ans -> data ;
    }
    else{
        cout<<"chapri";
    }
}