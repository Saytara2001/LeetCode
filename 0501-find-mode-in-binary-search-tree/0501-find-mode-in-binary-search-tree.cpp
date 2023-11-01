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
    map<int, int> mp;
    int mx = 0;
    void rec(TreeNode* root) {
        if(root == NULL)
            return;
        mx = max(mx, ++mp[root->val]);
        rec(root->right);
        rec(root->left);
    }
    vector<int> findMode(TreeNode* root) {
        rec(root);
        vector<int> v;
        for(auto it: mp) {
            if(it.second == mx)
                v.push_back(it.first);
        }
        return v;
    }
};