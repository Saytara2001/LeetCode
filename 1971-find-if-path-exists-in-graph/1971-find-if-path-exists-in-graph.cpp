class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> vis;
    bool dfs(int node, int dest) {
        if(node == dest) return true;
        vis[node] = true;
        int valid = 0;
        for(auto child: adj[node]) {
            if(!vis[child]) {
                valid |= dfs(child, dest);
            }
        }
        return valid;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        adj = vector<vector<int>> (n);
        vis = vector<bool> (n);
        for(auto it: edges) {
            adj[it[0]].push_back(it[1]); 
            adj[it[1]].push_back(it[0]);
        }
        return dfs(source, destination);
    }
};