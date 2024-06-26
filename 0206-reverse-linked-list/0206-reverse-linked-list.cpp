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
    ListNode* dfs(ListNode* head, ListNode* par) {
        if(!head) 
            return head;
        
        ListNode *ans = head;
        
        if(head->next) {
            ans = dfs(head->next, head);
        }
        
        head->next = par;
        
        return ans;
    }
    ListNode* reverseList(ListNode* head) {
        
        return dfs(head, NULL);
    }
};