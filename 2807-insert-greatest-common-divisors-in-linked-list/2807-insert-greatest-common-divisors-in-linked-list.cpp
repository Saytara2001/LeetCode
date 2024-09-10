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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* pre = head;  
        if(!head->next) {
             return head;
        }
        ListNode* nxt = head->next;
        while(nxt) {
            
            ListNode *cur = new ListNode();
            cur->val = __gcd(pre->val, nxt->val);
            
            cur->next = pre->next;
            pre->next = cur;
            
            pre = nxt;
            nxt = nxt->next;
        }
        
        return head;
    }
};