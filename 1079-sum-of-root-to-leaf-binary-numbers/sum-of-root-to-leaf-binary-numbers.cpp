/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root, int x) {
        if (root == NULL)
            return 0;

        x <<= 1;
        x |= root->val;

        if (root->left == nullptr and root->right == nullptr)
            return x;

        int left = dfs(root->left, x);
        int right = dfs(root->right, x);

        return left + right;
    }
    int sumRootToLeaf(TreeNode* root) {
        int x = 0;
        return dfs(root, x);
    }
};