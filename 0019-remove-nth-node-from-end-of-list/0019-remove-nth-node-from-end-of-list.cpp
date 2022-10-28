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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
//         we will take two pointers slow and fast 
        ListNode * slow=head , *fast=head;
//         now we will iterate first n nodes 
        while(n--){
            fast = fast ->next;
        }
        // if the node is head to be deleted then we return head;
        if(!fast) return head-> next;
         
//         now we will move one step each for slow and fast when fast reaches end the slow will be at n+1 th position
        while(fast-> next){
            slow = slow -> next;
            fast = fast -> next;
        }
//          now delete the node 
         slow -> next = slow -> next -> next;
         return head;
    }
};