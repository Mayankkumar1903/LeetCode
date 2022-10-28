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
    void reorderList(ListNode* head) {
//          first we will see brute force solution
//          let us consider 1->2->3->4->5->6
//         we have to convert it to 1->6->2->5->3->4
//           
        
//          first we will check if there is 0 , 1 or 2 node then we can't reorder
        if(!head || !head->next || ! head->next->next)
            return ;
//         we will travese the linked list and find the second last  node 
//         i.e , in the above example 5 and set the address contained in  1 to 6 and 6->2 and 1->6 and set 5->NULL
           
        ListNode * temp = head;
        while(temp-> next -> next)
            temp=temp-> next;
        
        temp-> next -> next= head->next;
        head-> next = temp-> next;
         
        temp-> next= NULL;
         
//          now we will do the above steps recusively
        
        reorderList(head-> next-> next);
    }
};