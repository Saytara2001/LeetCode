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
    int sz = 0;
    int cnt = 0;
    ListNode* middle;
    void reverse(ListNode* head) {
        if(head == NULL) return;
        sz++;
        reverse(head->next);
        if((sz + 1) / 2 == ++cnt) {
            middle = head;
            return;
        }
    }
   
    ListNode* middleNode(ListNode* head) {
        reverse(head);
        return middle;
    }
};