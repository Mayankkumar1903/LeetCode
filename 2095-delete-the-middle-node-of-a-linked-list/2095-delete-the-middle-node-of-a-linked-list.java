/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteMiddle(ListNode head) {
        //Explictly Handle for onely 1 node
        if(head.next == null) return null;
        // For only 2 node , delete the second node and return head
        if(head.next.next == null) {
            head.next = null;
            return head;
        }
        // We use two pointers one is fast and other is slow
        //slow gonna move one step and fast gonna move two step at a time
        // When fast becomes null , slow is at the node which we have to delete.
        ListNode slow = head, fast = head;
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        // just swap the values of slow with the slow's next node and delete the next node.
        // slow.next.val is always != null 
        slow.val = slow.next.val;
        slow.next = slow.next.next;
        // Finallly return original head.
        return head;
    }
}