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
    void dfs(TreeNode* root, long long& ans, int num) {
        
         if(!root->left and !root->right) {
             //this leaf node
            num = num *10 + root->val;
            ans += num;
            return;
        }
        
        num = num *10 + root->val;
        
        if(root->left) dfs(root->left , ans, num);
        if(root->right) dfs(root->right, ans, num);
        
    }
    int sumNumbers(TreeNode* root, int num = 0) {
        long long ans = 0;
        dfs(root, ans, 0);
        return ans;
    }
};