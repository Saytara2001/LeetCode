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
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN, lvl = 1, dep = 1;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()) {
            int curSum = 0;
            int sz = q.size();
            while(sz--) {
                auto cur = q.front();
                q.pop();
                curSum += cur->val;
                if(cur->left) q.push(cur->left); 
                if(cur->right) q.push(cur->right); 
            }
            if(maxSum < curSum) {
                maxSum = curSum;
                lvl = dep;
            }
            ++dep;
        }
        return lvl;
    }
};