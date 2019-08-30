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
   vector< vector<int> > ret;
    void calPath(TreeNode *root, int sum, int curSum, vector<int> tmp){
        if(root == NULL){
            return;
        }
        
      
        if(sum == root->val + curSum && root->left == NULL && root->right == NULL){
        tmp.push_back(root->val);
            ret.push_back(tmp);
        }
        tmp.push_back(root->val);
        calPath(root->left, sum ,curSum + root->val, tmp);
        calPath(root->right, sum , curSum + root->val, tmp);
        
        tmp.pop_back();
    }

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      //  vector< vector<int> > ret;
        
        if(root == NULL) {
            return ret;
        }
        
        vector<int> tmp;
        calPath(root, sum, 0, tmp);
        return ret;
    }
};