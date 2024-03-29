/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
    int maxDepthFind(TreeNode *root){
        if(!root) return 0;
        int l , r;
        l = maxDepthFind(root->left);
        r = maxDepthFind(root->right);
        if(l>r) return l+1;
        return r+1;
    }
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root==NULL) return 0;
        return maxDepthFind(root);
        
    }
};