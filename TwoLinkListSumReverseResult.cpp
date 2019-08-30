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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() 
        ListNode *i1 = l1, *i2 = l2;
        ListNode *head = new ListNode(-1);
        ListNode *tail = head; int c=0;
        while(i1!=NULL || i2!=NULL){
            int sum =0;
            if(i1!=NULL){sum+=i1->val;i1=i1->next;} 
            if(i2!=NULL){sum+=i2->val;i2=i2->next;} 
            sum+=c;
            c = sum/10;
            sum = sum%10;
            tail->next = new ListNode(sum);
            tail = tail->next;
        }
        if(c) {tail->next = new ListNode(c); tail = tail->next;}
        return head->next;
    }
};