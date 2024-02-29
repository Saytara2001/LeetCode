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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool lvl = 0;
        while(q.size()) {
            int prevNum = 0;
            int sz = q.size();
            //finish level by level
            while(sz--) {
                TreeNode* top = q.front();
                q.pop();
                if(top->left != NULL) q.push(top->left);
                if(top->right != NULL) q.push(top->right);
                if(lvl & 1) {
                    if((top->val & 1) or (prevNum != 0 and prevNum <= top->val))
                        return false;
                }else {
                    if(!(top->val & 1) or (prevNum != 0 and prevNum >= top->val))
                        return false;
                }
                prevNum = top->val;
            }
            lvl ^= 1;
        }
        return true;
    }
};