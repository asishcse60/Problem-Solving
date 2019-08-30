/*
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(p==NULL && q==NULL) return 1;
        if(p!=NULL && q!=NULL){
            if(p->val!=q->val) return 0;
            else{
                int k = isSameTree(p->left,q->left);
                int k1 = isSameTree(p->right,q->right);
                return k&k1;
            }
        }
        else return 0;

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
    public bool IsSameTree(TreeNode p, TreeNode q) {
        if(p==null && q == null) return true;
        if(p==null || q==null) return false;
        return (p.val == q.val) && IsSameTree(p.left, q.left) && IsSameTree(p.right, q.right);
    }
}
