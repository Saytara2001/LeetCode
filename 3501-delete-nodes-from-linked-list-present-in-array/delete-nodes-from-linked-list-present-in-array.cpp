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
    unordered_map<int, int> vis;
    ListNode* removeNode(ListNode* cur) {
        while(cur != nullptr and vis.count(cur->val)) {
            cur = cur->next;
        }
        ListNode* head = cur;
        ListNode* prev = head;
        while(cur != nullptr) {
            if(vis.count(cur->val)) {
                prev->next = cur->next;
                cur = cur->next;
            } else {
                prev = cur;
                cur = cur->next;
            }
        } 
        return head;
    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        for(auto x: nums) {
            vis[x] = true;
        }
        return removeNode(head);
    }
};