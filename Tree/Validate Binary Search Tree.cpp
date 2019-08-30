/*
Time: O(n)
space: O(1)
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
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
    bool IsBst(TreeNode *root , long long minValue, long long maxValue){

        if(!root) return true;
        if(root->val > maxValue || root->val < minValue)
         return false;
        return IsBst(root->left, minValue, root->val - 1) && IsBst(root->right, root->val + 1, maxValue);

    }
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL) return true;
        return IsBst(root, LLONG_MIN, LLONG_MAX);

    }
};
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}

/* Driver program to test above functions*/
int main()
{
  struct node *root = newNode(4);
  root->left        = newNode(2);
  root->right       = newNode(5);
  root->left->left  = newNode(1);
  root->left->right = newNode(3);

  if(isBST(root))
    printf("Is BST");
  else
    printf("Not a BST");

  getchar();
  return 0;
}
/**  C#
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public bool IsValidBST(TreeNode root) {
        if(root == null) return true;
        return IsBst(root , int.MaxValue, int.MinValue);
    }

    private bool IsBst(TreeNode root, int maxValue, int minValue){
        if(root==null) return true;
        if(root.val <= minValue || root.val >= maxValue) return false;
        return IsBst(root.left , root.val, maxValue) && IsBst(root.right, maxValue, root.val);
    }
}
