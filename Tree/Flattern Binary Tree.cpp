/*Given a binary tree, flatten it to a linked list in-place.*/
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
    public void Flatten(TreeNode root) {
        if(root==null) return;
        List<TreeNode>Nodes = new List<TreeNode>();
        PreOrderTraverse(root, Nodes );
        int count = Nodes.Count();
        for(int nodeIndex = 0; nodeIndex<count - 1; nodeIndex++){
        
           Nodes[nodeIndex].left = null;
           Nodes[nodeIndex].right= Nodes[nodeIndex + 1];
        }
        Nodes[count - 1].left = null;
        Nodes[count - 1].right= null;
    }
    
    public void PreOrderTraverse(TreeNode root, List<TreeNode>Nodes){
    
      if(root == null) return;
      Nodes.Add(root);
      if(root.left!=null)
      PreOrderTraverse(root.left, Nodes);
      if(root.right!=null)
      PreOrderTraverse(root.right, Nodes);
    }
}