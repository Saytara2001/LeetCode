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
    bool ok = true;
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        
        if(!root1 and !root2) // null null
            return true;
        
        if(!root1 or !root2) // null 5 (or) 3 null
            return false;
        
        if(root1->val != root2->val)
            return false;
        
        
        bool swap = flipEquiv(root1->left, root2->right) and 
                    flipEquiv(root1->right, root2->left);
        
        bool noSwap = flipEquiv(root1->left, root2->left) and 
                    flipEquiv(root1->right, root2->right);
        
        return swap | noSwap;
    }
};