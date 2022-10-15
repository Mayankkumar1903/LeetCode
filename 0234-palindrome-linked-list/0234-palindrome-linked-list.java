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
    public boolean isPalindrome(ListNode head) {
//       reverse the linked list and store it in another linked list
//         compare the two lists
        ListNode temp = new ListNode();
ListNode a = head;
ListNode pre = null;

while (a != null) {
	temp = new ListNode(a.val);
	temp.next = pre;
	pre = temp;
	a = a.next;
}

while (pre != null) {
	if (pre.val != head.val) 
		return false;
	pre = pre.next;
	head = head.next;
}

return true;
    }
}

