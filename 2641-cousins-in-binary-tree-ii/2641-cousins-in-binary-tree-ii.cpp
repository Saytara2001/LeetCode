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
    void calcSum(TreeNode* root, int dep, vector<int>& sums) {
        if(!root) 
            return;
        
        sums[dep] += root->val;
        
        calcSum(root->left, dep + 1, sums);   
        calcSum(root->right, dep + 1, sums);
    }
    void dfs(TreeNode* root, int dep, vector<int>& sums) {
        if(!root) return;
        
        if(root->left or root->right) {
            int children = 0;
            if(root->left) children += root->left->val;  
            if(root->right) children += root->right->val;

            if(root->left) 
                root->left->val = sums[dep + 1] - children;
            if(root->right) 
                root->right->val = sums[dep + 1] - children;
        }
        
        dfs(root->left, dep + 1, sums);   
        dfs(root->right, dep + 1, sums);
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        
        vector<int> sums(100000); // sum of each lvl in BT
        
        calcSum(root, 0, sums);  
        dfs(root, 0, sums);
        
        root->val = 0;
        
        return root;
    }
};