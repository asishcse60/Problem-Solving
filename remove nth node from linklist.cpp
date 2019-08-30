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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        struct ListNode *previous = head, *tail = head; int cnt = 0;
        for(int i = 0;i<n; i++) previous = previous->next;
        if(previous== NULL) return head->next;

        while(previous->next!=NULL){
            previous=previous->next;
            tail = tail->next;
        }
        tail->next =tail->next->next;
        return head;
    }
};