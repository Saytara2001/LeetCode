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
    int maxDepth = -1, leftMost = 0;
    int dfs(TreeNode* root, int dep) {
        if(root == NULL) return leftMost;
        if(dep > maxDepth) {
            maxDepth = dep;
            leftMost = root->val;
        }
        dfs(root->left, dep +  1);
        dfs(root->right, dep + 1);
        return leftMost;
    }
    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 0);
        return leftMost;
    }
};