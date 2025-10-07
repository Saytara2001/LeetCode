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
    int dfs(TreeNode* root, int maxValue) {
        if(root == nullptr) return 0;
        int left = dfs(root->left, max(maxValue, root->val));
        int right = dfs(root->right, max(maxValue, root->val));
        int cur = (maxValue <= root->val);
        return left + right + cur;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }
};