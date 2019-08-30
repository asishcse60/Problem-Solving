/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

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
 int getMaxDepth(TreeNode* root, int curDepth){
        if(root == NULL) return INT_MIN;
        if(root->left == NULL && root->right == NULL){
            return curDepth;
        }
        
        return max(getMaxDepth(root->left, curDepth + 1), getMaxDepth(root->right, curDepth + 1));
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return getMaxDepth(root, 1);
    }
};