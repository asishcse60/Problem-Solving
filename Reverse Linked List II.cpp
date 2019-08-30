/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 <=m <= n ? length of list.
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* tmp = new ListNode(0);
        tmp->next = head;
        ListNode* post; 
        ListNode* pre = tmp;
        for(int i = 1; i<=n; i++){
            if(i==m) post = pre;
            if(i>m && i<=n){
                pre->next = head->next;
                head->next=post->next;
                post->next=head;
                head=pre;
            }
            pre=head;
            head = head->next;
        }
        return tmp->next;
    }
};