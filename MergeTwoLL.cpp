#include<bits/stdc++.h> 
using namespace std;
class ListNode{
    public:
    int val;
    ListNode* next ;
    ListNode(int val){
        this -> val = val ;
        this -> next = NULL;

    }
};
void bubbleSort(vector<int>&arr, int n){

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
    ListNode* sortList(ListNode* head) {
        if(head == NULL)
            return NULL;
        if(head -> next == NULL)
            return head;

        vector<int>ans ;
        ListNode* temp = head;
        // storing data of LL into array 
        while(temp != NULL){
            ans.push_back(temp -> val);
            temp = temp -> next ;
        }
        int size = ans.size();
    
        // sorting the array
        bubbleSort(ans, size);
        
        ListNode* ansLL = head;
        int i = 0 ;
        while(ansLL != NULL){
            ansLL -> val = ans[i];
            i++;
            ansLL = ansLL -> next ;
            
        }
        return head;

    }
    int findLength(ListNode* head){
        ListNode* temp = head;
        int len = 0 ;
        while(temp != NULL){
            temp = temp -> next ;
            len ++ ;
        }
        return len ;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp = list1;
        int len = findLength(temp);
        int i = 0 ;
        while(i < len - 1){
            temp = temp -> next ;
            i++;
        }
        temp -> next = list2;
        ListNode* ans = sortList(list1);
        return ans ;
    }
    void print(ListNode* head){
        ListNode* temp = head;
        while(temp != NULL){
            cout<<temp -> val<<" ";
            temp = temp -> next ;
        }
        cout<<endl;
    }
int main(){
    ListNode* first = new ListNode(121);
    ListNode* second = new ListNode(211);
    ListNode* third = new ListNode(112);

    first -> next  = second ;
    second -> next = third ;
    
    ListNode* first1 = new ListNode(143);
    ListNode* second1 = new ListNode(314);
    ListNode* second2 = new ListNode(341);
    ListNode* third1 = new ListNode(413);
    ListNode* third2 = new ListNode(431);

    first1 -> next  = second1 ;
    second1 -> next = second2 ;
    second2 -> next = third1 ;
    third1 -> next = third2 ;


    ListNode* ans = mergeTwoLists(first, first1);
    print(ans);
}