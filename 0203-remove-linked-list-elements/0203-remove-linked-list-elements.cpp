/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        while(head and head->val == val) 
            head = head->next;
        
        ListNode *cur = head;
        
        while(cur and cur->next) {
            if(cur->next->val == val) {
                cur->next = cur->next->next;
            }else {
                cur = cur->next;
            }    
        }
        
        return head;
    }
};