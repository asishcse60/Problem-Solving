/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3
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
        map<int,int>mp;
        mp.clear();
        ListNode* tail=new ListNode(0);
        ListNode* tmp = tail;
        while(head!=NULL){
            if(mp[head->val]==0){
                mp[head->val] = 1;
                tail->next = new ListNode(head->val);
                tail=tail->next;
            }
            head=head->next;
        }
        return tmp->next;
    }
};