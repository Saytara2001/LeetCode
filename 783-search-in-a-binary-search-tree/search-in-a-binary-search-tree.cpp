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
    void dfs(TreeNode *cur, int val, TreeNode *&res) {
        if(cur == NULL) return;
        if(cur->val == val) {
            res = cur;
            return;
        }
        dfs(cur->left, val, res);
        dfs(cur->right, val, res);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode *res = NULL;
        dfs(root, val, res);
        return res;
    }
};