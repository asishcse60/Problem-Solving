/*
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
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
int mx;
    int rec(TreeNode *root){
        if(!root) return 0;
        int left = rec(root->left);
        int right = rec(root->right);
        int m = root->val;
        if(left>0) m+=left;
        if(right>0) m+=right;
        mx=max(mx,m);
        if(max(left,right) > 0) return max(left,right) + root->val;
        else return root->val;
    }
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        mx=-99999999;
        if(!root) return 0;
        rec(root);
        return mx;
        
    }
};