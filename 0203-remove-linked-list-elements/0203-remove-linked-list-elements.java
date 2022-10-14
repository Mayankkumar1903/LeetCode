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
    public ListNode removeElements(ListNode head, int value) {
        ListNode dummy=new ListNode(-1);
        dummy.next=head;
        // if(head==null) return null;
        // if(head.next==null&&head.val==value)return null;
      ListNode temp=dummy;
        while(temp.next!=null&&temp!=null){
            if(temp.next.val==value)
                temp.next=temp.next.next;
            else
                temp=temp.next;
        }
        return dummy.next;
        
    }
}