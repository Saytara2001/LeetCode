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
    // pair<int, int> dfs2(TreeNode* node) {
    //         if(!node)
    //              return {0, 0};
    //         pair<int, int> cur = {1, node->val}; // current node
            
    //         pair<int, int> ch1 = dfs2(node->left);
    //         pair<int, int> ch2 = dfs2(node->right);

    //         pair<int, int> sum = {ch1.first + ch2.first, ch1.second + ch2.second};
    //         return sum;
    //     }

    int averageOfSubtree(TreeNode* root) {
        int nodes = 0;
        function<pair<int, int>(TreeNode*)> dfs = [&](TreeNode* node) {

            if(!node)
                 return make_pair(0, 0);

            pair<int, int> cur = {1, node->val}; // current node
            
            pair<int, int> ch1 = dfs(node->left);
            pair<int, int> ch2 = dfs(node->right);

            pair<int, int> sum = {ch1.first + ch2.first + cur.first,
                                     ch1.second + ch2.second + cur.second};

            if(sum.second / sum.first == node->val) ++nodes;
            return sum;
        };

        dfs(root);

        return nodes;
    }
};