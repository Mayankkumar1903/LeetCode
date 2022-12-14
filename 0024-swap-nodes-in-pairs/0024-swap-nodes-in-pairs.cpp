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
    ListNode* swapPairs(ListNode* head) {
//          base case
        if(head == NULL || head-> next == NULL)
            return head;
        
//         by swapping the values not the node;
         ListNode * temp = head;
        while( temp && temp-> next){
            if(temp -> next)
            swap( temp->val, temp->next-> val);
            temp= temp-> next ->next;
        }
        return head;
    }
};