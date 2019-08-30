/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    
        if(head==NULL) return head;
        ListNode* tmp = head;
        ListNode* l1 = new ListNode(0); ListNode* L1 = l1;
        ListNode* l2 = new ListNode(0); ListNode* L2 = l2;
        ListNode* temp=L1;
        while(tmp!=NULL){
            if(tmp->val<x) {
                l1->next = new ListNode(tmp->val);
                l1 = l1->next;
                tmp = tmp->next;
            }
            else{
                l2->next = new ListNode(tmp->val);
                l2 = l2->next;
                tmp=tmp->next;
            }
        }
        l1->next = L2->next;
        return L1->next;
        
    }
};