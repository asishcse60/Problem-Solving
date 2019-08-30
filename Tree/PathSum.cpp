//Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    bool hasPathSum(TreeNode* root, int sum, int curSum){
        if(root==NULL) return false;
        if(root->left == NULL && root->right==NULL && curSum+root->val==sum) return true;
        return hasPathSum(root->left, sum, curSum + root->val) || hasPathSum(root->right, sum, curSum + root->val);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        hasPathSum(root, sum, 0);
    }
};

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
    public bool HasPathSum(TreeNode root, int sum) {
        return HasPathSum(root, sum, 0);
        
    }
    public bool HasPathSum(TreeNode root, int sum, int curSum){
        if(root == null) return false;
        if(root.left == null && root.right==null && curSum+root.val == sum) return true;
        return HasPathSum(root.left, sum, curSum + root.val) || HasPathSum(root.right, sum, curSum + root.val);
    }
}