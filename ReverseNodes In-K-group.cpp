/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
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
    struct Node{
          int val;
          Node *next;
          Node *prev;
    };
    
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        Node *tmp = new Node;
        Node *tail = tmp;
        ListNode* P = new ListNode(0); 
        ListNode* p = P;
        ListNode* HH = head;
        tail->prev=NULL;
        if(head==NULL || k <= 1) return head;
        int cnt = 0;
        while(head!=NULL)
        {
            tail->val = head->val;
            tail->next = new Node;
            tail->next->prev = tail;
            tail=tail->next;
            head=head->next;
            cnt++;
            if(cnt == k)
            {
                
                Node* list = tail;
                list=list->prev;  
                while(list!=NULL)
                {
                         p->next = new ListNode(list->val);
                         list=list->prev;
                         p=p->next;
                 }
                 cnt=0;
                 delete tail;
                 delete list;
                 delete tmp;
                 tmp=new Node;
                 tail = tmp;
            }
        }
        
       if(cnt>0)
       {   
           Node* tt = tmp;
            while(tt!=tail){
                p->next = new ListNode(tt->val);
                tt=tt->next;
                p=p->next;
            }
       }
       return P->next;
    }
};