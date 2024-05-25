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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode *res = head;
        ListNode *p1, *p2;
        p1 = p2 = head;
        
        while(p2 != NULL) {
            while(p2 != NULL and p1->val == p2->val) {
                p2 = p2->next;
            }
            p1->next = p2;
            p1 = p1->next;
        }
        
        return res;
    }
};