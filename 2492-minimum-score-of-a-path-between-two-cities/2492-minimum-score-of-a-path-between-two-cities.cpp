class Solution {
public:
    vector<int> vis;
    int mn = 1e9;
    void dfs(int node, vector<vector<pair<int, int>>>& adj) {
        vis[node] = 1;
        for(auto child:adj[node]) {
            mn = min(mn, child.second);
            if(!vis[child.first]) {
                dfs(child.first, adj);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n+1);
        vis = vector<int> (n+1, 0);
        for(auto vv:roads) {
            adj[vv[0]].push_back({vv[1], vv[2]});
            adj[vv[1]].push_back({vv[0], vv[2]});
        }
        dfs(1, adj);
        return mn;
    }
};