/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<long long> bfs(TreeNode* root) {
        vector<long long> sums;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()) {
            int sz = q.size();
            long long curSum = 0;
            while(sz--) {
                TreeNode* cur = q.front();
                q.pop();
                
                curSum += cur->val;
                
                if(cur->right) q.push(cur->right);                                     if(cur->left) q.push(cur->left);
            }
            sums.push_back(curSum);
        }
        return sums;
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        vector<long long> sums = bfs(root);
        
        if(sums.size() < k)
            return -1;
        
        sort(begin(sums), end(sums), greater<>());
        
        return sums[k - 1];
    }
};