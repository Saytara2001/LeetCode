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
    int dfs(TreeNode* root, string gen) {
        if(root == NULL) {
            return 0;
        }
        gen += char(root->val + '0');
        if(root->left == nullptr and root->right == nullptr) {
            int res = 0, n = gen.size();
            for(int pow = 0; pow < n; pow++) {
                res += (1 << pow) * (gen[n - pow - 1] - '0');
            }
            return res;
        }
        int left = dfs(root->left, gen);
        int right = dfs(root->right, gen);

        return left + right;
    }
    int sumRootToLeaf(TreeNode* root) {
        string s = "";
        return dfs(root, s);
    }
};