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
    bool dfs(TreeNode* root) {
        if(root->left == NULL and root->right == NULL) 
            return root->val;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int ans = 0;
        if(root->val == 2) {
            ans = left | right;
        }else {
            ans = left & right;
        }
        return ans;
    }
    bool evaluateTree(TreeNode* root) {
        return dfs(root);
    }
};