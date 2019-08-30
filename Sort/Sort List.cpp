/**
 * Sort a linked list in O(n log n) time using constant space complexity.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
      bool cmpPtr(ListNode* a, ListNode* b){
      return a->val < b->val;
      }
      ListNode* sortList(ListNode* head) {
        if (NULL == head) return head;
        vector<ListNode* > nodes;
        ListNode *cnode = head;
        while (cnode !=NULL)
        {
            nodes.push_back(cnode);
            cnode = cnode->next;
        }
        sort(nodes.begin(), nodes.end(), cmpPtr);
        head = nodes[0];
        for (int i = 0; i < nodes.size() - 1; ++i){
            nodes[i]->next = nodes[i + 1];
        }
        nodes.back()->next = NULL;
        return head;
    }

};