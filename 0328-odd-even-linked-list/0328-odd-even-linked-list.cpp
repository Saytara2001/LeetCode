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
    ListNode* oddEvenList(ListNode* head) {
        
        if(!head or !head->next) 
            return head;
        
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *startEven = even;
        
        while(even->next and odd->next) {
            
            if(even->next) {
                odd->next = even->next;
                odd = odd->next;
            }
            
            if(odd->next) {
                even->next = odd->next;
                even = even->next;
            }
        }
        if(even->next) {
            even->next = NULL;
        }
        if(odd->next) {
            odd->next = NULL;
        }
        odd->next = startEven;
        return head;
    }
};