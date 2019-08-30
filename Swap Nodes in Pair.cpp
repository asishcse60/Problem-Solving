/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *p = new ListNode(0);
        p->next = head;
        head =p;
        while(1){
            if(p->next==NULL) break;
            if(p->next->next==NULL) break;
            ListNode *p1 = p->next;
            ListNode *q1 = p1->next;
            p1->next = q1->next;
            q1->next = p1;
            p->next = q1;
            p=p1;
        }
        return head->next;
    }
};