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
    ArrayList<Integer> arr=new ArrayList<>();
    public void inorder(TreeNode root){
        if(root==null)return ;
        inorder(root.left);
        arr.add(root.val);
        inorder(root.right);
        return ;
    }
    public int rangeSumBST(TreeNode root, int low, int high) {
        if(root==null)return 0;;
        inorder(root);
        int sum=0;
        for(Integer num:arr){
            if(num>=low&&num<=high)
                sum+=num;
        }
        return sum;
    }
}