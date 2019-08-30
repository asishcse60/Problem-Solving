/**complexity is O(n).
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public List<int>rightViewNodeValue = new List<int>();
    public List<int> RightSideView(TreeNode root) {
        if(root == null) return rightViewNodeValue;
        int maxLevel = 0;
        GenerateRightViewOfTree(root, 1, ref maxLevel);
        return rightViewNodeValue;
    }
    
    public void GenerateRightViewOfTree(TreeNode root, int level, ref int maxLevel){
    
        if(root == null) return;
        if(level > maxLevel){
            maxLevel = level;
            rightViewNodeValue.Add(root.val);
        }
        GenerateRightViewOfTree(root.right, level + 1, ref maxLevel);
        GenerateRightViewOfTree(root.left, level + 1, ref maxLevel);
    }
}