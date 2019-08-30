/*Time Complexity: O(n^2). Worst case occurs when tree is left skewed. 
Example Preorder and Inorder traversals for worst case are {A, B, C, D} and {D, C, B, A}.
Given preorder and inorder traversal of a tree, construct the binary tree.
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
    public int preIndex = 0;
    public TreeNode BuildTree(int[] preorder, int[] inorder) {

      return BuildTree(0, preorder.Length - 1, preorder, inorder);
    }
    
    public TreeNode BuildTree(int start, int end, int[] preorder, int[] inorder){
        if(start > end) return null;
        int rootIndex = SearchQuery(start, end, inorder, preorder[preIndex]);
        if(rootIndex == -1) return null;
        TreeNode temp = new TreeNode(preorder[preIndex++]);
        temp.left = BuildTree(start , rootIndex - 1, preorder, inorder);
        temp.right = BuildTree(rootIndex + 1, end, preorder, inorder);
        return temp;
    }

    
    public int SearchQuery(int start, int end, int[] inorder,int queryValue){
    
        for(int i = start; i<=end; i++)
           if(inorder[i] == queryValue)
             return i;
        return -1;
    }
}