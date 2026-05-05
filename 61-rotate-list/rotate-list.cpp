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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL or k == 0)
            return head;
        int len = 0;
        ListNode* cur = head;
        ListNode* tail = head;
        while (cur != NULL) {
            tail = cur;
            cur = cur->next;
            ++len;
        }
        k %= len;
        if (k == 0)
            return head;
        ListNode* newTail = head;
        for (int i = 0; i < len - k - 1; i++) {
            newTail = newTail->next;
        }
        cout << tail->val << " " << newTail->val << endl;
        ListNode* newHead = newTail->next;
        tail->next = head;
        newTail->next = NULL;

        return newHead;
    }
};