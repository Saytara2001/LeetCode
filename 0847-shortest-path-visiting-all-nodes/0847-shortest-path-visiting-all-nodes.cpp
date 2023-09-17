class Solution {
public:
    int bfs(vector<vector<int>>& graph) {
        
        queue<pair<int, pair<int, int>>> q; //node, distance, mask
        set<pair<int ,int>> vis; //node, mask
        int n = graph.size();
        int finalMask = (1LL << n) - 1; //1111 => all is ones
        
        for(int i = 0; i < n; i++) {
            q.push({i, {0, 1LL << i}});
            vis.insert({i, 1LL << i});
        }
        
        while(q.size()) {
            int node = q.front().first;
            int dis = q.front().second.first; 
            int mask = q.front().second.second;
            q.pop();
            
            for(auto child: graph[node]) {
                
                int newMask = (mask | (1LL << child));
 
                if(newMask == finalMask)
                    return dis + 1;
                
                if(vis.find({child, newMask}) != end(vis))
                    continue;
                
                q.push({child, {dis + 1, newMask}});
                vis.insert({child, newMask});
            }
        }
        
        return 0;
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        return bfs(graph);
    }
};