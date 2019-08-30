/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 = k = BST's total elements.
*/
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
    public int KthSmallest(TreeNode root, int k) {
        
        int ans = 0;
        inOrderTraverse(root, ref k, ref ans);
        return ans;
    }
    
    public bool inOrderTraverse(TreeNode root, ref int k, ref int ans){
    
        if(root == null) return false;
        if(inOrderTraverse(root.left, ref k, ref ans)) return true;
        if((--k)==0){
            ans = root.val;
            return true;
        }
        return inOrderTraverse(root.right, ref k, ref ans);
    }
}