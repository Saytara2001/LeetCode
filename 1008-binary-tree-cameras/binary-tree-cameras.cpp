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
    // 1 => has_camera
    // 2 => covered
    // 3 => need camera
    int cameras = 0;
    
    int dfs(TreeNode *root) {

        if(!root)
            return 2;

        int L = dfs(root->left);
        int R = dfs(root->right);

        // we must add camera at this node
        if(L == 3 or R == 3) {
            cameras++;
            return 1;
        }

        // we don't need to add camera at this node
        if(L == 1 or R == 1) {
            return 2;
        }

        return 3;

    }
    int minCameraCover(TreeNode* root) {
        return dfs(root) == 3 ? ++cameras: cameras;
    }
};