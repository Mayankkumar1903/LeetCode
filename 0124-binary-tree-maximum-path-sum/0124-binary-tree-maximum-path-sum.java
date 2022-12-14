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
     private int globalMaxSum = Integer.MIN_VALUE;
    private int maxStartingFromRoot(TreeNode root) {
        if (root == null) {
            return 0;
        }
        
        //#1 max sum 'starting' from the left node of the root. In given example max starting from 15
        int leftMaxSum = maxStartingFromRoot(root.left);
        
        //#2 max sum 'starting' from the right node of the root. Max starting from 7
        int rightMaxSum = maxStartingFromRoot(root.right);
        
        //#3- Max of self and self+whichever of left right is greater. 20+15
        int localMaxSum = Math.max(root.val, root.val+Math.max(leftMaxSum, rightMaxSum));
        
        //Max of 'starting' from self (20+15) and 'including self in path with left and right children' (15+20+7). 
        int maxIncludingPathLeftRootRight = Math.max(localMaxSum, root.val+leftMaxSum+rightMaxSum);
        
        //Update globalMaxSum which is maintaining max for the whole tree (outside of this recursion)
        globalMaxSum = Math.max(globalMaxSum, maxIncludingPathLeftRootRight);
        
        //Return only max of 'starting' from current node. so that the parent (-10) can form a path without repeating current node (20) twice!
        return localMaxSum;
    }

  public int maxPathSum(TreeNode root) {
    maxStartingFromRoot(root);
    return globalMaxSum;
  }
}