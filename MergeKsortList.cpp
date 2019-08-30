/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
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
    ListNode* merg2(ListNode* l1, ListNode* l2){
        
        if(l1==NULL && l2==NULL) return l1;
        else if(l1==NULL) return l2;
        else if(l2==NULL) return l1;
        ListNode* head = new ListNode(0);
        ListNode* tmp = head;
        ListNode* L1 = l1;
        ListNode* L2 = l2;
        
        while(L1!=NULL && L2!=NULL){
              if(L1->val<=L2->val){
                  tmp->next = new ListNode(L1->val);
                  L1 = L1->next;
                  tmp=tmp->next;
              }
              else{
                  tmp->next= new ListNode(L2->val);
                  L2 = L2->next;
                  tmp=tmp->next;
              }
        }
        if(L1!=NULL){
            while(L1!=NULL){
                tmp->next= new ListNode(L1->val);
                L1=L1->next;
                tmp=tmp->next;
            }
        }
       else if(L2!=NULL){
            while(L2!=NULL){
                tmp->next= new ListNode(L2->val);
                L2=L2->next;
                tmp=tmp->next;
            }
        }
        return head->next;
        
    }
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(lists.empty()) return NULL;
        ListNode* head = lists.back();
        lists.pop_back();
        
        while (!lists.empty()){
            head = merg2(head,lists.back());
            lists.pop_back();
        }
        return head;
    }
};