/*
Complexity:O(n)
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
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
    void CalculateSum(TreeNode *root, int curNum, int &ans){
        if(root->left == NULL && root->right==NULL){
            curNum = curNum * 10 + root->val;
            ans+=curNum;
            return;
        }
        curNum = curNum * 10 + root->val;
        if(root->left!=NULL) CalculateSum(root->left, curNum, ans);
        if(root->right!=NULL) CalculateSum(root->right, curNum, ans);
    }
    int sumNumbers(TreeNode* root) {
      if(root == NULL) return 0;
      int ans = 0;
      CalculateSum(root, 0, ans);
      return ans;
    }
};
/*
public class TreeNode{
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int x){val = x;}
}C#
*/

public class Solution {
    public int SumNumbers(TreeNode root) {
       if(root==NULL)    return 0;
       int totalSum = 0;
       CalculateSum(root, 0, ref totalSum);
       return totalSum;
    }

    public void CalculateSum(TreeNode root, int curNum, ref int totalSum){

        if(root.left==null && root.right==null){
            curNum = curNum*10 + root.val;
            totalSum+=curNum;
            return;
        }
        curNum = curNum*10 + root.val;
        if(root.left!=null) CalculateSum(root.left, curNum, ref totalSum);
        if(root.right!=null) CalculateSum(root.right, curNum,ref totalSum);
    }
}
