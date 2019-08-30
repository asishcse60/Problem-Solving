/**
Time Complexity: O(n^2) in worst case. For a skewed tree, printGivenLevel() takes O(n) time where n is the number of nodes in the skewed tree. So time complexity of printLevelOrder() is O(n) + O(n-1) + O(n-2) + .. + O(1) which is O(n^2).
 Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {

    List<List<int>>levelOrderList = new List<List<int>>();
    public List<List<int>> LevelOrder(TreeNode root) {
        
        if(root == null) return levelOrderList ;
        
        var height = GetHeight(root);
        for(int level = 1; level<=height; level++){
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

//Complexity:O(n) queue
#include <stdio.h>
#include <stdlib.h>
#define MAX_Q_SIZE 500
 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
 
/* frunction prototypes */
struct node** createQueue(int *, int *);
void enQueue(struct node **, int *, struct node *);
struct node *deQueue(struct node **, int *);
 
/* Given a binary tree, print its nodes in level order
   using array for implementing queue */
void printLevelOrder(struct node* root)
{
  int rear, front;
  struct node **queue = createQueue(&front, &rear);  
  struct node *temp_node = root; 
 
  while(temp_node)
  {
    printf("%d ", temp_node->data);
 
    /*Enqueue left child */
    if(temp_node->left)
      enQueue(queue, &rear, temp_node->left);
 
    /*Enqueue right child */
    if(temp_node->right)
      enQueue(queue, &rear, temp_node->right);
 
    /*Dequeue node and make it temp_node*/
    temp_node = deQueue(queue, &front);
  }
}
 
/*UTILITY FUNCTIONS*/
struct node** createQueue(int *front, int *rear)
{
  struct node **queue =
   (struct node **)malloc(sizeof(struct node*)*MAX_Q_SIZE);  
 
  *front = *rear = 0;
  return queue;
} 
 
void enQueue(struct node **queue, int *rear, struct node *new_node)
{
  queue[*rear] = new_node;
  (*rear)++;
}     
 
struct node *deQueue(struct node **queue, int *front)
{
  (*front)++;
  return queue[*front - 1];
}     
 
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
 
/* Driver program to test above functions*/
int main()
{
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5); 
 
  printf("Level Order traversal of binary tree is \n");
  printLevelOrder(root);
 
  getchar();
  return 0;
}
Run on IDE
Time Complexity: O(n) where n is number of nodes in the binary tree