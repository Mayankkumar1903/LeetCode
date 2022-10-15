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
    public ListNode deleteDuplicates(ListNode head) {
         HashSet<Integer> set = new HashSet();
        ListNode temp = head;
        ListNode nonDuplicate = null;
        while(temp!=null){
            if(!set.contains(temp.val)){
               set.add(temp.val);
                nonDuplicate=temp;
            }else{
                nonDuplicate.next=temp.next;
            }
            temp=temp.next;
        }
        return head;
    }
}
 // head.next = deleteDuplicates(head.next);
        // return head.val == head.next.val ? head.next : head;