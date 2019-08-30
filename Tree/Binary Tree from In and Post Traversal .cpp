/*Time Complexity: O(n^2). Worst case occurs when tree is left skewed. 
Example Preorder and Inorder traversals for worst case are {A, B, C, D} and {D, C, B, A}.
Given inorder and postorder traversal of a tree, construct the binary tree.
*/
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * } in PostOrder right recursion call first, then left recursion
 */
public class Solution {
    public int postIndex;
    public TreeNode BuildTree(int[] inorder, int[] postorder) {
        if(inorder.Length!=postorder.Length) return null;
        postIndex = inorder.Length - 1;
        return BuildTree(0,  inorder.Length - 1, inorder, postorder);
    }
    
    public TreeNode BuildTree(int start,  int end, int[] inorder, int[] postorder){
        if(start > end) return null;
        int rootIndex = SearchQuery(start, end, inorder, postorder[postIndex]);
        if(rootIndex == -1) return null;
        TreeNode temp = new TreeNode(postorder[postIndex--]);
        temp.right = BuildTree(rootIndex + 1,  end, inorder, postorder);
        temp.left = BuildTree(start,  rootIndex - 1, inorder, postorder);
        
        return temp;
    }
    
    public int SearchQuery(int start, int end, int[] inorder, int queryValue){
    
        for(int i = start; i<=end; i++){
            if(inorder[i] == queryValue)
            return i;
        
        }
    
        return -1;
    }
}