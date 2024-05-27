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
    bool isPalindrome(ListNode* head) {
        ListNode *slow, *fast;
        slow = fast = head;
        
        //find the middle (slow)
        while (fast and fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        //reverse second half
        ListNode *prev = NULL;
        while(slow) {
            ListNode *tmp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = tmp;
        }
        
        //check plaindrome
        ListNode *left = head;
        while(prev) {
            if(left->val != prev->val)
                return false;
            left = left->next;
            prev = prev->next;
        }
        
        return true;
    }
};