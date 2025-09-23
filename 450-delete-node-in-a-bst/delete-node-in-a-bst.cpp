class Solution {
public:
    TreeNode *minVal(TreeNode *root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    TreeNode *dfs(TreeNode *root, int key) {
        if (root == nullptr)
            return nullptr;
        if (key < root->val) {
            root->left = dfs(root->left, key);
        } else if (key > root->val) {
            root->right = dfs(root->right, key);
        } else {
            // Node Found
            if (root->left == nullptr && root->right == nullptr)
                return nullptr;
            else if (root->left == nullptr) {
                return root->right;
            } else if (root->right == nullptr) {
                return root->left;
            } else {
                TreeNode *successor = minVal(root->right);
                // Copy successor's value to current node
                root->val = successor->val;
                // Delete the successor from right subtree
                root->right = dfs(root->right, successor->val);
            }
        }
        return root;
    }

    TreeNode *deleteNode(TreeNode *root, int key) {
        root = dfs(root, key);
        return root;
    }
};