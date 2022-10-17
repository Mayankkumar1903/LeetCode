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
    List<Integer> res= new ArrayList<>();//global ArrayList 

    public List<Integer> preorderTraversal(TreeNode root)
    {
         if(root==null)//base case for the null graph 
             return res;

         preorder(root);//calling the preorder in order  

         return res;//returning gthe resultant array list 
    }

    public void preorder(TreeNode root)
    {
        if(root==null)//base case when we reach to the null node while recuring down hill, returning to the calling function and deleting the  activation record 
            return;//returning to the call function or the active acttib=vation record 
        
        res.add(root.val);//adding first the value, as we first see the root we are adding it to the ArrayList (Root Left Right)
        
        preorder(root.left);//recursing down hill in search of left node 
        preorder(root.right);//after the left node is done fo the particular activation record , we are going downhill for the right node search 
        
        return;//returning to the calling function or the active activation record and deleting this activation record as all the fuction are completed 
    }

}