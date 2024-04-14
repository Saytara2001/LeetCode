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
    int dfs(TreeNode* root, bool isLeft) {
        if(root == NULL) return 0;
        if(root->left == NULL and root->right == NULL) 
            return isLeft ? root->val : 0;
        return dfs(root->left, 1) + dfs(root->right, 0);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, 0);
    }
};