/**
Complexity:O(n)
Given a binary tree, find the maximum path sum.
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
   
    public int MaxPathSum(TreeNode root) {
        if(root.left == null && root.right==null) return root.val;
        int maxPathSum = int.MinValue;
        CalculateMaxPathSum(root, ref maxPathSum);
        return maxPathSum;
    }
    
    public int CalculateMaxPathSum(TreeNode root, ref int maxPathSum){
    
            if(root == null) return 0;
            
            int ls = CalculateMaxPathSum(root.left, ref maxPathSum);
            int rs = CalculateMaxPathSum(root.right,ref maxPathSum);
            
            int curSum = root.val;
            if(ls > 0) curSum += ls;
            if(rs > 0) curSum += rs;
            
            maxPathSum = Math.Max(curSum, maxPathSum);
            
            if(Math.Max(ls, rs) > 0) return Math.Max(ls, rs) + root.val;
    
          return root.val;
    }
}