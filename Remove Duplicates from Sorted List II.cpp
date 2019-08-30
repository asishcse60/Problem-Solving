/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* tail = new ListNode(0);
        ListNode* tmp = tail;
        int pivot = 999999999;
        while(head!=NULL){ 
              if(head->next!=NULL && (head->val==head->next->val)) {pivot = head->val;}
              else{
                  if(pivot!=head->val)
                  {tail->next = new ListNode(head->val);tail=tail->next;pivot=999999999;} 
              }
             head = head->next;    
        }
        return tmp->next;
    }
};