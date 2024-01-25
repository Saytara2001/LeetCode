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
    int dfs(TreeNode* root, int path) {
        
        if(root == NULL)
            return 0;
        
        path ^= (1 << root->val);
        
        if(root->left == NULL and root->right == NULL) 
            return ((path & (path - 1)) == 0);
        
        return dfs(root->left, path) + dfs(root->right, path);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        return dfs(root, 0);
    }
};