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
    TreeNode* res;
    void dfs(TreeNode *cur, int val) {
        if(cur == NULL) return;
        if(cur->val == val) {
            res = cur;
            return;
        }
        dfs(cur->left, val);
        dfs(cur->right, val);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        res = NULL;
        dfs(root, val);
        return res;
    }
};