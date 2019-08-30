/**
Time Complexity: The worst case time complexity of this method is O(n^2). For a skewed tree, printGivenLevel() takes O(n) time where n is the number of nodes in the skewed tree. So time complexity of printLevelOrder() is O(n) + O(n-1) + O(n-2) + .. + O(1) which is O(n^2).
 * Definition for a binary tree node.
 Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {

    List<List<int>>levelOrderList = new List<List<int>>();
    public List<List<int>> LevelOrderBottom(TreeNode root) {
        
        if(root == null) return levelOrderList ;
        
        var height = GetHeight(root);
        for(int level = height; level>=1; level--){
          levelOrderList.Add(GetLevelOrderList(new List<int>(), level, root));
        }
        return levelOrderList ;
    }
    public List<int>GetLevelOrderList(List<int>levelList, int level, TreeNode root){
        
        if(root == null) return levelList;
        if(level == 1) levelList.Add(root.val);  
        else if(level > 1){
        GetLevelOrderList(levelList , level - 1, root.left);
        GetLevelOrderList(levelList , level - 1, root.right);
        }
        return levelList;
    }
    
    public int GetHeight(TreeNode root){
        
        if(root == null) return 0; 
        return Math.Max(GetHeight(root.left) + 1, GetHeight(root.right) + 1);
    
    }
}
//Complexity: O(n) Stack
// A C++ program to print REVERSE level order traversal using stack and queue
// This approach is adopted from following link
// http://tech-queries.blogspot.in/2008/12/level-order-tree-traversal-in-reverse.html
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
 
/* A binary tree node has data, pointer to left and right children */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
 
/* Given a binary tree, print its nodes in reverse level order */
void reverseLevelOrder(node* root)
{
    stack <node *> S;
    queue <node *> Q;
    Q.push(root);
 
    // Do something like normal level order traversal order. Following are the
    // differences with normal level order traversal
    // 1) Instead of printing a node, we push the node to stack
    // 2) Right subtree is visited before left subtree
    while (Q.empty() == false)
    {
        /* Dequeue node and make it root */
        root = Q.front();
        Q.pop();
        S.push(root);
 
        /* Enqueue right child */
        if (root->right)
            Q.push(root->right); // NOTE: RIGHT CHILD IS ENQUEUED BEFORE LEFT
 
        /* Enqueue left child */
        if (root->left)
            Q.push(root->left);
    }
 
    // Now pop all items from stack one by one and print them
    while (S.empty() == false)
    {
        root = S.top();
        cout << root->data << " ";
        S.pop();
    }
}
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
node* newNode(int data)
{
    node* temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
 
    return (temp);
}
 
/* Driver program to test above functions*/
int main()
{
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left  = newNode(6);
    root->right->right = newNode(7);
 
    cout << "Level Order traversal of binary tree is \n";
    reverseLevelOrder(root);
 
    return 0;
}
Run on IDE
Output:

Level Order traversal of binary tree is
4 5 6 7 2 3 1
Time Complexity: O(n) where n is number of nodes in the binary tree.