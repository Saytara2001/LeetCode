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
    int dfs(TreeNode* root, int mx, int mn) {
        if(root == NULL) return mx - mn;
        int left = dfs(root->left, max(mx, root->val), min(mn, root->val));
        int right = dfs(root->right, max(mx, root->val), min(mn, root->val));
        return max(left, right);
    }
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);;
    }
};