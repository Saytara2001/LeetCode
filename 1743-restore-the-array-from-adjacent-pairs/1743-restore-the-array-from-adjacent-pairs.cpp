class Solution {
public:
    map<int, vector<int>> adj;
    vector<int> res;
    void dfs(int node, int par) {
        res.push_back(node);
        for(auto child: adj[node]) {
            if(par != child) {
                dfs(child, node);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        for(auto it: adjacentPairs) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(auto it: adj) {
            if(size(it.second) == 1) {
                dfs(it.first, -1);
                break;
            }
        }
        return res;
    }
};