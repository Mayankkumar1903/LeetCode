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
         // create a stack using Stack() class 
    
	    Stack<Integer> stack = new Stack<Integer>();
    
        // assign temp to the head and push all nodes into stack
        ListNode temp = head;
        while (temp!= null)
        {
              stack.push(temp.val);
              temp=temp.next;
         }
    
       // now again make temp as head and performing 
       // stack pop() compare first element of linkedlist
      // and top of satck
      // at any moment ,if the values are not equal return false;
    
      temp = head;
      while (temp != null)
      {
            if (stack.pop() != temp.val)
                 return false;
           temp = temp.next;
      }
    
      // if traversal of linkedlist and stack pops are equal return true
     return true;
    }
}

