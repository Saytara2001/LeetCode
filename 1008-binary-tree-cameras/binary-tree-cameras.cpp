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
    enum Camera {Has_Camera, Covered, NeedToCovered};
    int cameras = 0;
    
    Camera dfs(TreeNode *root) {

        if(!root)
            return Camera::Covered;

        Camera L = dfs(root->left);
        Camera R = dfs(root->right);

        // we must add camera at this node
        if(L == Camera::NeedToCovered or R == Camera::NeedToCovered) {
            cameras++;
            return Camera::Has_Camera;
        }

        // we don't need to add camera at this node
        if(L == Camera::Has_Camera or R == Camera::Has_Camera) {
            return Camera::Covered;
        }

        return Camera::NeedToCovered;

    }
    int minCameraCover(TreeNode* root) {
        return dfs(root) == Camera::NeedToCovered ? ++cameras: cameras;
    }
};