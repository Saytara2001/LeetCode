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
    const int mod = 1e9 + 7;
    int dfsSum(TreeNode* root) {
        if(root == NULL) return 0;

        int leftSum = dfsSum(root->left);
        int rightSum = dfsSum(root->right);

        root->val += leftSum + rightSum;
        return root->val;
    }
    long long ans = 0, sum = 0;
    void getMaxProduct(TreeNode* root) {
        if(root == NULL) return;
        getMaxProduct(root->left);
        getMaxProduct(root->right);
        int cur = sum - root->val;
        ans = max(ans, 1LL * cur * root->val);
    }
    int maxProduct(TreeNode* root) {
        sum = dfsSum(root);
        getMaxProduct(root);
        return ans % mod;
    }
};