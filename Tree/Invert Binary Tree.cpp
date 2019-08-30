/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode InvertTree(TreeNode root) {
        if(root == null) return root;
        SwapTreeNode(root);
        return root;
    }
    
    public void SwapTreeNode(TreeNode root){
    
        if(root==null) return;
        TreeNode temp = root.left;
        root.left = root.right;
        root.right = temp;
        if(root.left!=null)
            SwapTreeNode(root.left);
        if(root.right!=null)    
        SwapTreeNode(root.right);
        return;
    }
}