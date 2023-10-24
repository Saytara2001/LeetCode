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
    vector<int> v;
    void rec(TreeNode* root, int depth) {
        if(root == NULL)
            return;
        if(v.size() > depth) {
            v[depth] = max(v[depth], root->val);
        }else {
            v.push_back(root->val);
        }
        rec(root->right, depth + 1);
        rec(root->left, depth + 1);
    }
    vector<int> largestValues(TreeNode* root) {
        rec(root, 0);
        return v;
    }
};