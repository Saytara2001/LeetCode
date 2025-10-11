/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr or root == p or root == q) 
            return root;

        TreeNode* left = dfs(root->left, p, q);
        TreeNode* right = dfs(root->right, p, q);

        if(left == NULL) return right;
        else if(right == NULL) return left;
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};