/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

// declare a queue that keeps the node;
// add the root element to queue;
// pop the element from queue and add the left and right node to queue;

class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> flist=new LinkedList<List<Integer>>();
        Queue<TreeNode> que=new LinkedList<TreeNode>();
        if(root==null)return flist;
        que.add(root);
        while(!que.isEmpty())
        {
            int temp=que.size();
            List<Integer> slist=new LinkedList<Integer>();
            for(int i=0;i<temp;i++){
                if(que.peek().left!=null)que.add(que.peek().left);
                if(que.peek().right!=null)que.add(que.peek().right);
                slist.add(que.poll().val);
            }
            
            flist.add(slist);
        }
        return flist;
    }
}