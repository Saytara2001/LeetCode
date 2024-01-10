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
    unordered_map< int, vector<int> > adj;
    void convert(TreeNode* root, int parent) {
        if(root == NULL) 
            return;
        if(parent != 0) {
            adj[root->val].push_back(parent);
            adj[parent].push_back(root->val);
        }
        convert(root->left, root->val);
        convert(root->right, root->val);
    }
    int amountOfTime(TreeNode* root, int start) {
        //convert binary tree to graph
        convert(root, 0); 
        //do bfs after create graph
        queue<int> q;
        q.push(start);
        map<int, bool> vis;
        vis[start] = 1;
        int time = 0;
        while(q.size()) {
            int sz = q.size();
            while(sz--) {
                int node = q.front();
                q.pop();

                for(auto child: adj[node]) {
                    if(!vis[child]) {
                        q.push(child);
                        vis[child] = 1;
                    }
                }
            }
            time++;
        }
        return time - 1;
    }
};