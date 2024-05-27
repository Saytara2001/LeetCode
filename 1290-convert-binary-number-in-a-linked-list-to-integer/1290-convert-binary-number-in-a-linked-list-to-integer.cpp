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
    int pow = 0;
    int rec(ListNode *head) {
        if(!head)
            return 0;
        int res = rec(head->next);
        
        return res + (1 << pow++) * head->val;
    }
    int getDecimalValue(ListNode* head) {
        return rec(head);
    }
};