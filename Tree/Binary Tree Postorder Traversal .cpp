/*
Time Complexity: O(n)
Given a binary tree, return the postorder traversal of its nodes' values.
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

    public List<int>Nodes  = new List<int>();
    public List<int> PostorderTraversal(TreeNode root) {
        if(root == null) return Nodes;
        PostorderTraversal(root.left);
        PostorderTraversal(root.right);
        Nodes.Add(root.val);
        return Nodes;
    }
}
//iterative approach
public IList<int> PostorderTraversal(TreeNode root) {
    List<int> arrList = new List<int>();
    if (root == null) return arrList;
    Stack<TreeNode> s1 = new Stack<TreeNode>();
    Stack<TreeNode> s2 = new Stack<TreeNode>();
    s1.Push(root);
   while (s1.Count > 0)
    {
        TreeNode temp = s1.Pop();
        s2.Push(temp);
        if (temp.left!=null)
        {
            s1.Push(temp.left);
        }
        if ( temp.right!=null)
        {
            s1.Push(temp.right);
        }
     }

   while (s2.Count > 0)
       arrList.Add(s2.Pop().val);
 return arrList;
}