/*
complexity: O(n)
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:

    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root==NULL) return 1;
        queue<TreeNode* >lt,rt;
        TreeNode *l,*r;
        lt.push(root->left); rt.push(root->right);
        while(!lt.empty() && !rt.empty()){
            l = lt.front(); r = rt.front();
            lt.pop(); rt.pop();
            if(l==NULL && r==NULL) continue;
            else if(l==NULL || r==NULL) return 0;
            else if(l->val!=r->val) return 0;
            lt.push(l->left); lt.push(l->right);
            rt.push(r->right); rt.push(r->left);
        }
        if(lt.empty() && rt.empty()) return 1;
        return 0;

    }
};
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
    bool isSymmetric(TreeNode *left, TreeNode *right){
        if(left == NULL && right == NULL) return true;
        if(left == NULL || right == NULL) return false;
        return (left->val == right->val) && isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
     return isSymmetric(root->left, root->right);
    }
};
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }C#
 */
public class Solution {
    public bool IsSymmetric(TreeNode root) {
        if(root == null)
          return true;
          return IsSymmetric(root.left , root.right);
    }
    public bool IsSymmetric(TreeNode left , TreeNode right){
        if(left == null && right == null)
            return true;
        if(left == null || right == null)
            return false;
        return (left.val == right.val) && IsSymmetric(left.left, right.right) && IsSymmetric(left.right, right.left);
    }
}
