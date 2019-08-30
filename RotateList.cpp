/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL || k == 0) return head;
        ListNode *p=head; int len = 0;
        while(p!=NULL){
            len++;
            p=p->next;
        }
        p=head;
        int move = len -(k%len) - 1;
        while(move>0){
            move--;
            p=p->next;
        }
        ListNode * q = p->next;
        if(q==NULL) return head;
        while(q->next!=NULL){
            q=q->next;
        }
        q->next = head;
        q = p->next;
        p->next=NULL;
        return q;
    }
};