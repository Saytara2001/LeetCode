class Solution {
public:
    int bfs(int node, vector<vector<pair<int, bool>>>& adj, int n) {
        
        int res = 0;
        queue<int> q;
        vector<bool> vis(n);
        
        q.push(node);
        vis[node] = 1;
        
        while(!q.empty()) {
            node = q.front();
            q.pop();
            
            for(auto child:adj[node]) {
                if(!vis[child.first]) {
                    if(child.second)
                        res++;
                    vis[child.first] = 1;
                    q.push(child.first);
                }
            }
        }
        return res;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, bool>>> adj(n);
        for(auto vv:connections) {
            adj[vv[0]].push_back({vv[1], 1}); //1 for given direction
            adj[vv[1]].push_back({vv[0], 0}); //0 for not given direction
        }
        return bfs(0, adj, n);
    }
};