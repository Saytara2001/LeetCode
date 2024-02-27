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
    int maxDiameter = 0;
    int DFS(TreeNode* root) {
        
        if(root == NULL) return 0;

        int left = DFS(root->left); 
        int right = DFS(root->right);
        
        maxDiameter = max(maxDiameter, left + right);
        
        return max(left, right) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        DFS(root);
        return maxDiameter;
    }
};