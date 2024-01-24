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
    int dfs(TreeNode* root, vector<int> freq) {
        if(root == NULL) {
            return 0;
        }
        
        freq[root->val]++;
        
        if(root->left == NULL and root->right == NULL) {
            int odd = 0;
            for(auto it: freq) {
                if(it > 0 and it % 2 == 1) odd++;
            }
            return (odd <= 1);
        }
        return dfs(root->left, freq) + dfs(root->right, freq);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> freq(10);
        return dfs(root, freq);
    }
};