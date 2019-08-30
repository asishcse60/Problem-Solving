/*
Time Complexity: O(n)
Given a binary tree, return the preorder traversal of its nodes' values.
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
    public List<int>Nodes = new List<int>();
    public List<int> PreorderTraversal(TreeNode root) {
        if(root==null) return Nodes;
        Nodes.Add(root.val);
        PreorderTraversal(root.left);
        PreorderTraversal(root.right);
        return Nodes;
    }
}
//iterative approach
public IList<int> PreorderTraversal(TreeNode root) {
    List<int> arrList=new List<int> ();
    if ( root==null) return arrList;
    Stack<TreeNode> S = new Stack<TreeNode> ();
    S.Push(root);
    while ( S.Count>0)
    {
        TreeNode temp= S.Pop();
        arrList.Add(temp.val);
        if ( temp.right!=null)
         S.Push(temp.right);
        if ( temp.left!=null)
         S.Push(temp.left);
    }
    return arrList;
}