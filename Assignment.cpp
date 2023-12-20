#include<bits/stdc++.h>
using namespace std;
class ListNode{
    public:
    int val ;
    ListNode* next ;
    ListNode(int data ){
        this -> val = data ;
        this -> next = NULL ;
    }
};
class Node{
    public:
    int data;
	Node * next;
	Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
};
void merge(vector<int>&array, int const left, int const mid,
           int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;
 
    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
 
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
 
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
 
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
 
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
 
// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(vector<int>&array, int const begin, int const end)
{
    if (begin >= end)
        return;
 
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}


    ListNode* sortList(ListNode* &head) {
        // make an array consisting of all val as same as head LL have 
        // sort the arrray using merge sort 
        // phir sorted array ko LL m convert krdo 

        vector<int> arr ;
        ListNode* temp = head ;
        while(temp != NULL){
            arr.push_back(temp -> val);
            temp = temp -> next ;

        }
        int end = arr.size();
        mergeSort(arr, 0, end - 1);
        for(int i = 0 ; i< arr.size() ;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        ListNode* curr = head ;
        for(int i = 0 ; i < end ; i++){
            curr -> val = arr[i];
            curr = curr -> next ;
        }
        return head ;
    }
    void print(ListNode* head){
        while(head != NULL){
            cout<<head -> val <<" ";
            head = head -> next ;
        }
        cout <<endl;
    }
    int main(){
        Node* first = new Node(4);
        Node* second = new Node(2);
        Node* third = new Node(1);
        Node* fourth = new Node(3);

        first -> next = second ;
        second -> next = third ;
        third -> next = fourth ; 

        print(first);
        ListNode* ans = sortList(first );
        print(ans);
    }