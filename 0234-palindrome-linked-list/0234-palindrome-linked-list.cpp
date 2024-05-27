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
    ListNode *cur;
    bool ok = true;
    bool rec(ListNode *head) {
        
        if(!head) 
            return 0;
        
        rec(head->next);
        
        ok &=( head->val == cur->val);
        cur = cur->next;
        
        return ok;
    }
    bool isPalindrome(ListNode* head) {
        cur = head;
        return rec(head);
    }
};