/*
Time Complexity: O(n)
Given a binary tree, return the inorder traversal of its nodes' values.
*/
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {

    public List<int>Nodes = new List<int>();
    public List<int> InorderTraversal(TreeNode root) {
        if(root == null) return Nodes;
        InorderTraversal(root.left);
        Nodes.Add(root.val);
        InorderTraversal(root.right);
        return Nodes;
    }
}
//Iterative approach
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        unordered_set<TreeNode*> myNode;
        vector<int> solution;
        stack<TreeNode*> mystack;
        if(root) mystack.push(root);
        while(!mystack.empty()){
            TreeNode* curNode=mystack.top();
            if (myNode.count(curNode)==0){
                mystack.pop();
                if(curNode->right)
                    mystack.push(curNode->right);
                mystack.push(curNode);
                if(curNode->left)
                    mystack.push(curNode->left);
                myNode.insert(curNode);
            }
            else{
                mystack.pop();
                solution.push_back(curNode->val);
            }
        }
        return solution;
    }
};