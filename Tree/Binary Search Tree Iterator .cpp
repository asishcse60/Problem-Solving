/**
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
 * Definition for binary tree
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */

public class BSTIterator {

    Stack<TreeNode>stack = new Stack<TreeNode>();
    public BSTIterator(TreeNode root) {
      TraverseLeftNode(root);
    }

    /** @return whether we have a next smallest number */
    public bool HasNext() {
        return stack.Count > 0;
    }

    /** @return the next smallest number */
    public int Next() {
        TreeNode popNode = stack.Pop();
        TraverseLeftNode(popNode.right);
        return popNode.val;
    }
    public void TraverseLeftNode(TreeNode temp){
        while(temp!=null){
            stack.Push(temp);
            temp = temp.left;
        }
    
    }
}
