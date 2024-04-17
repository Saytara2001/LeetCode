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
    string t = string(8500, 'z');
    string dfs(TreeNode* root, string s) {
        
        if(root == NULL) return t;
        
        s += (char)(root->val + 'a');
        
        if(root->left == NULL and root->right == NULL) {
            string rev = s;
            reverse(begin(rev), end(rev));
            if(t > rev) t = rev;
            return t;
        }
        
        string tmp = dfs(root->left, s);
        tmp = min(tmp, dfs(root->right, s));
        
        return tmp;
    }
    string smallestFromLeaf(TreeNode* root) {
        string s = "";
        return dfs(root, s);
    }
};