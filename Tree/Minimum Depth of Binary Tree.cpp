/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
    public int MIN_DEPTH = int.MaxValue;
    public int MinDepth(TreeNode root) {
        
        if(root == null) return 0;
 
        return GetMinDepth(root, 1);
        return MIN_DEPTH;
        
    }
    public int GetMinDepth(TreeNode root, int curDepth){
    
    
        if(root==null) return MIN_DEPTH ;
        if(root.left==null && root.right==null){
          return curDepth;
        }
        return Math.Min(GetMinDepth(root.left, curDepth + 1), 
         GetMinDepth(root.right, curDepth + 1));
    }
}