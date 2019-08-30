class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return new TreeNode(head->val);
        ListNode *fast = head->next->next, *slow = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *root = new TreeNode(slow->next->val);
        root->right = sortedListToBST(slow->next->next);
        slow->next = NULL;
        root->left = sortedListToBST(head);
        return root;
    }
};