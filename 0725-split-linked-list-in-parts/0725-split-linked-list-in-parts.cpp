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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        int n = 0;
        ListNode* cur = head;
        
        while(cur != NULL) {
            ++n;
            cur = cur->next;
        }
        
        int sz = n / k;
        int rem = k > n ? 0 : n % k;
        
        
        cur = head;
        
        vector<ListNode*> res;
        while(cur != NULL) {
            ListNode* ptr = cur;
            int x = 1;
            while(x < sz and cur->next) {
                cur = cur->next;
                ++x;
            }
            if(rem and cur->next) {
                --rem;
                 cur = cur->next;
            }
            
            ListNode* nxt = cur->next;
            cur->next = NULL;
            
            res.push_back(ptr);
            cur = nxt;
            
        }
        while(res.size() < k) res.push_back(nullptr);
        return res;
    }
};