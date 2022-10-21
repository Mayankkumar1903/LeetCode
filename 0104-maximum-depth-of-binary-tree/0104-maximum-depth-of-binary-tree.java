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
class Solution {
    public int maxDepth(TreeNode root) {
        int depth=0;
        Queue<TreeNode> que=new LinkedList<TreeNode>();
        if(root==null)return 0;
        que.add(root);
        while(!que.isEmpty()){
            int size=que.size();
            for(int i=0;i<size;i++){
                TreeNode node=que.remove();
                if(node.left!=null)que.add(node.left);
                if(node.right!=null)que.add(node.right);
            }
            depth++;
         
            
            
        }
        return depth;
    }
}