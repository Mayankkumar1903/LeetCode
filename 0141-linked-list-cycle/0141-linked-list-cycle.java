/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
//         if there is one element;
        if(head == null )
            return false;
//         If there is no cycle, the fast pointer will stop at the end of the linked list.
    // If there is a cycle, the fast pointer will eventually meet with the slow pointer.
        ListNode slow = head, fast = head;
        
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;      
            //  if slow pointer met the same value as of fast pointer then it means linked list contains cycle inside it
            if(slow == fast)
                return true;
        }
        
        return false;
    }
}