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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i]) pq.push({lists[i] -> val, i});
        }
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        while (!pq.empty()) {
            int min_index = pq.top().second;
            pq.pop();
            cur -> next = lists[min_index];
            cur = cur -> next;
            lists[min_index] = lists[min_index] -> next;
            cur -> next = nullptr;
            if (lists[min_index]) pq.push({lists[min_index] -> val, min_index});
        }
        return head -> next;
    }
};