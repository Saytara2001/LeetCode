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
 typedef long long ll;
class Solution {
public:
    int paths = 0;
    void dfs(TreeNode* root, int targetSum, ll curSum, unordered_map<ll, int>& freq) {
        if(root == NULL) 
            return;

        curSum += root->val;
        paths += freq[curSum - targetSum];
        ++freq[curSum];

        dfs(root->left, targetSum, curSum, freq);
        dfs(root->right, targetSum, curSum, freq);

        --freq[curSum];
        curSum -= root->val;
        
    };
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<ll, int> freq;
        ++freq[0];
        dfs(root, targetSum, 0, freq);
        return paths;   
    }
};