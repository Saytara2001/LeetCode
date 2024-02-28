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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        int leftMost = 1;
        q.push(root);
        while(q.size()) {
            int sz = q.size();
            leftMost = q.front()->val;
            while(sz--) {
                TreeNode* top = q.front();
                q.pop();
                if(top->left != NULL) q.push(top->left);
                if(top->right != NULL) q.push(top->right);
            }
        }
        return leftMost;
    }
};