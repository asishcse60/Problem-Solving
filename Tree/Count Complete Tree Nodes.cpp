/*Given a complete binary tree, count the number of nodes.*/
/**
complexity: log n^2
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public int CountNodes(TreeNode root) {
        if(root == null) return 0;
        return CountNode(root);
    }
    
    public int CountNode(TreeNode root){
        if(root==null) return 0;
                
        int leftTreeDepth = GetLeftTreeDepth(root);
        int rightTreeDepth = GetRightTreeDepth(root);
        
        if(leftTreeDepth == rightTreeDepth){
            return GetPow(leftTreeDepth + 1) - 1; //2^h+1 - 1;
        }
        else{
            return 1 + CountNode(root.left) + CountNode(root.right);
        }
    }
    public int GetLeftTreeDepth(TreeNode root){
        TreeNode temp = root;
        int depth = 0;
        while(temp!=null){
            if(temp.left!=null){
              depth++;   
              temp = temp.left;
            }
            else break;

        }
        return depth;
    }
    public int GetRightTreeDepth(TreeNode root){
        TreeNode temp = root;
        int depth = 0;
        while(temp!=null){
            if(temp.right!=null){
              depth++;   
              temp = temp.right;
            }
            else break;
        }
        return depth;
    }
     public int GetPow(int  h){
        int depth = 1;
        for(int i = 0; i<h; i++)
         depth*=2;
        return depth;
    }
}