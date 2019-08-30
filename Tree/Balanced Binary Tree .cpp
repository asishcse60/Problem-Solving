/**
Time Complexity: O(n^2) Worst case occurs in case of skewed tree.
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public bool IsBalanced(TreeNode root) {
        if(root == null) return true;
        return IsBalanceBst(root);
    }
    public bool IsBalanceBst(TreeNode root){
        
        if(root == null) return true;
        int leftDepth = height(root.left);
        int rightDepth = height(root.right);
        if(Math.Abs(leftDepth-rightDepth)<=1 && IsBalanceBst(root.left) && IsBalanceBst(root.right))
        return true;
        return false;
        
    }
    int height(TreeNode node)
{
   /* base case tree is empty */
   if(node == null)
       return 0;
 
   /* If tree is not empty then height = 1 + max of left
      height and right heights */
   return 1 + Math.Max(height(node.left), height(node.right));
} 

//O(n)
This optimization reduces time complexity to O(n).

/* program to check if a tree is height-balanced or not */
#include<stdio.h>
#include<stdlib.h>
#define bool int
 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
  int data;
  struct node* left;
  struct node* right;
};
 
/* The function returns true if root is balanced else false
   The second parameter is to store the height of tree.  
   Initially, we need to pass a pointer to a location with value 
   as 0. We can also write a wrapper over this function */
bool isBalanced(struct node *root, int* height)
{
  /* lh --> Height of left subtree 
     rh --> Height of right subtree */   
  int lh = 0, rh = 0;  
 
  /* l will be true if left subtree is balanced 
    and r will be true if right subtree is balanced */
  int l = 0, r = 0;
     
  if(root == NULL)
  {
    *height = 0;
     return 1;
  }
 
  /* Get the heights of left and right subtrees in lh and rh 
    And store the returned values in l and r */   
  l = isBalanced(root->left, &lh);
  r = isBalanced(root->right,&rh);
 
  /* Height of current node is max of heights of left and 
     right subtrees plus 1*/   
  *height = (lh > rh? lh: rh) + 1;
     
  /* If difference between heights of left and right 
     subtrees is more than 2 then this node is not balanced
     so return 0 */
  if((lh - rh >= 2) || (rh - lh >= 2))
    return 0;
     
  /* If this node is balanced and left and right subtrees 
    are balanced then return true */
  else return l&&r;
}
 
 
/* UTILITY FUNCTIONS TO TEST isBalanced() FUNCTION */
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
    struct node* node = (struct node*)
                                malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return(node);
}
 
int main()
{
  int height = 0;
    
  /* Constructed binary tree is
             1
           /   \
         2      3
       /  \    /
     4     5  6
    /
   7
  */   
  struct node *root = newNode(1);  
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->left->left->left = newNode(7);
 
  if(isBalanced(root, &height))
    printf("Tree is balanced");
  else
    printf("Tree is not balanced");    
 
  getchar();
  return 0;
}
Run on IDE
Time Complexity: O(n)
