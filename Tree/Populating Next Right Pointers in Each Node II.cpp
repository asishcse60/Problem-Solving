Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    TreeLinkNode *getNextRight(TreeLinkNode *root){
            TreeLinkNode* temp = root->next;
            while(temp!=NULL){
                if(temp->left!=NULL) return temp->left;
                if(temp->right!=NULL) return temp->right;
                temp = temp->next;
            }
             return NULL;
    }
    void connectNextPointer(TreeLinkNode *root){
        if(root == NULL) return;
        if(root->next!=NULL)
        connectNextPointer(root->next);
        if(root->left)
        {
            if(root->right)
            {
               root->left->next = root->right;
               root->right->next = getNextRight(root);
             }
             else
             root->left->next = getNextRight(root);
             connectNextPointer(root->left);
         }
        else if(root->right){
            root->right->next = getNextRight(root);
            connectNextPointer(root->right);
        }
        else
        connectNextPointer(getNextRight(root));

    }
    void connect(TreeLinkNode *root) {
        if(root==NULL) return;
       root->next = NULL;
       connectNextPointer(root);
    }
};