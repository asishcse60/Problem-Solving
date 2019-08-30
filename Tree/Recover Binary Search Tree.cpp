/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
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
    void fixBst(TreeNode *root, TreeNode* &first,  TreeNode* &middle, TreeNode* &prev){
        if(!root) return;
        fixBst(root->left, first, middle, prev);
        if(prev!=NULL && (prev->val)> root->val){

            if(first==NULL){
                first = prev;
                middle = root;
            }
            else
            middle = root;
        }
        prev = root;
        fixBst(root->right, first, middle,  prev);
    }
    void recoverTree(TreeNode* root) {
        TreeNode* prev = NULL;
        TreeNode* first = NULL;
        TreeNode* middle = NULL;
        fixBst(root, first, middle, prev);
        if(first!=NULL){
        int t = first->val;
           first->val = middle->val;
           middle->val =t;
        }

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
    public void RecoverTree(TreeNode root) {
        TreeNode prev = null;
        TreeNode first = null;
        TreeNode second = null;
        fixBst(root ,  ref prev, ref first,ref second);
        if(first!=null){
            int tValue = first.val;
            first.val = second.val;
            second.val = tValue;
        }
    }

    public void  fixBst(TreeNode root ,  ref TreeNode prev, ref TreeNode first,ref TreeNode second){

        if(root==null) return;
        fixBst(root.left,ref prev, ref first,  ref second);
        if(prev!=null && prev.val > root.val){// rules violate for Bst
            if(first == null){
                first = prev;
                second = root;
            }
            else{
                second = root;
            }
        }
        prev = root;
        fixBst(root.right, ref prev, ref first, ref second);
    }
}
