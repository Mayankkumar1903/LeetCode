/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
//          base case
         if(head == NULL || head -> next == NULL) 
             return head;
        
//         now we will apply merge sort logic 
//          1-> first find the mid by using slow and fast pointer/ hare - tortoise algo
//         2-> apply merge sort on both the halves 
//          3-> merge the two sorted halves
        
        ListNode* temp=NULL;
        ListNode * slow= head;
        ListNode * fast = head;
        
        while( fast != NULL && fast -> next != NULL)
        {
            temp = slow;
             fast = fast-> next -> next;
             slow = slow -> next;
        }
        temp -> next =NULL; //As it is the end of the first list 
        // the seond list starts from slow to fast;
        // the first list starts from head to temp;
        
        ListNode * l1= sortList(head);
        ListNode * l2= sortList(slow);
        
        return merge(l1,l2);
    }

    
    // Merge function will return the sorted list ;
    
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* newHead= new ListNode(0);
        ListNode* dummy = newHead;
        
        while( l1 != NULL && l2 != NULL){
            if( l1 -> val <= l2-> val){
                dummy-> next=l1;
                l1= l1 -> next;
                dummy = dummy -> next;
            }
            else{
                dummy -> next = l2;
                l2 = l2 -> next;
                dummy = dummy -> next;
            }
        }
        
//         if there is remaining elements in list;
        
        while(l1 != NULL)
        {
            dummy -> next = l1;
            l1= l1 -> next;
            dummy = dummy -> next;
        }
        while( l2 != NULL){
                dummy -> next = l2;
                l2 = l2 -> next;
                dummy = dummy -> next;
        }
        return newHead-> next;
    }
};