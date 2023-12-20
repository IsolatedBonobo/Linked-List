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
Node* reverse_recursion(Node* prev, Node* curr){
    if(curr == NULL){
        return prev ;
    }
    Node* forward = curr -> next ;
    curr -> next = prev ;
    Node* ans = reverse_recursion(curr, forward);

    return ans ;
}
int getlen(Node* head){
    Node* temp = head;
    int len = 0;
    while(temp != NULL){
        len ++;
        temp = temp -> next ;
    }
    return len ;
}
Node* addTwoNum(Node* l1, Node* l2){
        int len1 = getlen(l1);
        int len2 = getlen(l2);
        Node* prev = NULL;
        l1 = reverse_recursion(prev, l1);
        l2 = reverse_recursion(prev, l2);


        Node* temp1 = l1;
        Node* temp2 = l2;
        int data = 0;
        vector<int> ans ;
        if(len1 == len2){
            
            while(temp1 != NULL && temp2 != NULL){
                int data = data + temp1 -> data + temp2 -> data;
                int carry = data / 10;
                int value = data % 10;
                ans.push_back(value);
                data = 0;
                data += carry ;
                temp1 = temp1 -> next ;
                temp2 = temp2 -> next ;
                }
                if(data != 0){
                    ans.push_back(data); 
                }
        }
        else if(len1 > len2 ){
            while(temp2 != NULL){
                int data = data + temp1 -> data + temp2 -> data;
                int carry = data / 10;
                int value = data % 10;
                ans.push_back(value);
                data = 0;
                data += carry ;
                temp1 = temp1 -> next ;
                temp2 = temp2 -> next ;
            }
            if(data != 0){
                data += temp1 ->  data;
                int value = data / 10 ;
                int carry = data % 10 ;
                ans.push_back(carry);
                
            }
            while(temp1 != NULL){
                
                
            }
            
        }
        
}
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp -> data <<" ";
        temp = temp -> next ;

    }
    cout<<endl;
}
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
        
        for(int i =0;i<size ;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;

        // sorting the array
        bubbleSort(ans, size);
        for(int i =0;i<size ;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    Node* ansLL = head;
    int i = 0 ;
    while(ansLL != NULL){
        ansLL -> data = ans[i];
        i++;
        ansLL = ansLL -> next ;
        
    }
    return head;
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
    
    Node* head = sortLL(first);
    print(head);
}