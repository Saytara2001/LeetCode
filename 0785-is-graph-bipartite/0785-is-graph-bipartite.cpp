class Solution {
public:
    vector<vector<int>> adj;
    bool ok = 1;
    vector<int> color;
    void bfs(int node, int n) {
        
        queue<int> q;
        
        color[node] = 1;
        q.push(node);
        
        while(!q.empty()) {
            
            node = q.front();
            q.pop();
            
            for(auto child:adj[node]) {
                if(!color[child]) {
                    color[child] = 3 - color[node];
                    q.push(child);
                }else {
                    if(color[node] == color[child])
                        ok = 0;
                }
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        adj = vector<vector<int>> (n);
        color = vector<int> (n);
        for(int i = 0; i < n; i++) {
            for(int j = 0 ; j < graph[i].size() ; j++) {
                adj[i].push_back(graph[i][j]);
            }
        }
        for(int i = 0; i < n; i++) {
            if(!color[i])
                bfs(i, n);
        }
        return ok;
    }
};