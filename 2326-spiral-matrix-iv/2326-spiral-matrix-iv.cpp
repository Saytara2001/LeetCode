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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        swap(n, m);
        vector<vector<int>> v(n, vector<int>(m, -1));
        
        auto valid = [&](int x, int y) {
            return (x >= 0 and x < n and y >= 0 and y < m and v[x][y] == -1);
        };
            
        int x = 0, y = 0, dire = 0;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        
        while(head) {
            v[x][y] = head->val;
            
            int nx = x + dx[dire];
            int ny = y + dy[dire];
            
            if(!valid(nx, ny)) {
                dire = (dire + 1) % 4;
                nx = x + dx[dire];
                ny = y + dy[dire];
            }
            
            
            
            x = nx, y = ny;
            head = head->next;
        }
        
        return v;
    }
};