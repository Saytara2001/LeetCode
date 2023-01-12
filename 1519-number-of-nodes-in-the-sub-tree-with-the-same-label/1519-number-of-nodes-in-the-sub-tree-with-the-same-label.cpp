class Solution {
public:
    vector<int> dfs(int node,int par, string& labels, vector<vector<int>>& adj, vector<int>& sub){
        vector<int> nodeCounts(26);
        nodeCounts[labels[node]-'a'] = 1;
        
        for(auto& child:adj[node]){
            
            if(child == par) continue;
            
            vector<int> childCounts = dfs(child, node, labels, adj, sub);
            
            for(int i = 0; i <= 25 ; i++){
                nodeCounts[i] += childCounts[i];
            }
        }
        
        sub[node] = nodeCounts[labels[node]- 'a'];
        return nodeCounts;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> sub(n, 0);
        dfs(0, -1, labels, adj, sub);
        return sub;
    }
};