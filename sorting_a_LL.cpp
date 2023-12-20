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
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp -> data <<" ";
        temp = temp -> next ;

    }
    cout<<endl;
}
void bubbleSort(vector<int>&arr, int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
  
        // If no two elements were swapped
        // by inner loop, then break
        if (swapped == false)
            break;
    }
}
Node* sortLL(Node* head){
    vector<int>ans ;
        Node* temp = head;
        // storing data of LL into array 
        while(temp != NULL){
            ans.push_back(temp -> data);
            temp = temp -> next ;
        }
        int size = ans.size();
        
        // sorting the array
        bubbleSort(ans, size);
        
        Node* ansLL = head;
        int i = 0 ;
        while(ansLL != NULL){
            ansLL -> data = ans[i];
            i++;
            ansLL = ansLL -> next ; 
        }
        return head;
}
Node* SortInLessTime(Node* head){

}
int main(){
    Node* first = new Node(121);
    Node* second= new Node(12);
    Node* third = new Node(230);
    Node* fourth = new Node(23);
    Node* fifth = new Node(5);

    first -> next = second ;
    second -> next = third ;
    third -> next = fourth ;
    fourth -> next = fifth ;
    print(first);
    Node* head = sortLL(first);
    print(head);
    
}