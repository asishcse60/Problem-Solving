/*
Complexity:  //Catalan number (2n)! / (n+1)!n!
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
    void rec(int cur, int end, vector<TreeNode* >&ans){
        if(cur>end) ans.push_back(NULL);
        else{
            for(int i = cur; i<=end; i++){
                vector<TreeNode* >LeftTree;
                rec(cur,i-1,LeftTree);
                vector<TreeNode* >RightTree;
                rec(i+1,end,RightTree);
                for(int l = 0; l<LeftTree.size(); l++){
                    for(int r = 0; r<RightTree.size(); r++){
                         TreeNode* root = new TreeNode(i);
                         root->left = LeftTree[l];
                         root->right = RightTree[r];
                         ans.push_back(root);
                    }
                }
            }
        }
    }
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<TreeNode* >ans;
        rec(1,n,ans);
        return ans;

    }
};
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * } C#
 */
public class Solution {

    void GenerateBst(int left, int right, IList<TreeNode>BstList){
        if(left > right){
            BstList.Add(null);
        }
        for(int curIndex = left; curIndex<= right; curIndex++){
            IList<TreeNode>leftTree = new List<TreeNode>();
            GenerateBst(left , curIndex - 1, leftTree);
            IList<TreeNode>rightTree=new List<TreeNode>();
            GenerateBst(curIndex + 1, right, rightTree);
            for(int leftTreeIndex = 0; leftTreeIndex<leftTree.Count; leftTreeIndex++){
                for(int rightTreeIndex = 0; rightTreeIndex<rightTree.Count; rightTreeIndex++){
                    TreeNode root = new TreeNode(curIndex);
                    root.left = leftTree[leftTreeIndex];
                    root.right = rightTree[rightTreeIndex];
                    BstList.Add(root);
                }
            }
        }
    }
    public IList<TreeNode> GenerateTrees(int n) {
        IList<TreeNode>BstList = new List<TreeNode>();
        GenerateBst(1 , n, BstList);
        return BstList;
    }
}
