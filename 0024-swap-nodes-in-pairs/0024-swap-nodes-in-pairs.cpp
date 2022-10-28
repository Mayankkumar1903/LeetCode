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
// base case
  if (head == NULL || head->next == NULL)
        return head;

        
//          swapping the nodes;
        
        
    ListNode *curr = head;
    ListNode *newHead = head->next;
    while(curr && curr->next){
        ListNode *temp = curr;
        curr = temp->next;
        temp->next = curr->next;
        curr->next = temp;
        curr = temp->next;
        if(curr && curr->next)
            temp->next = curr->next;
    }
    return newHead;
    }
};

 