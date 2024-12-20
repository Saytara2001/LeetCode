class Solution {
public:
    int timer;
    vector<int> lowLink, dfn;
    vector<vector<int>> bridges;
    void tarjan(int node, int par, vector<vector<int>>& adj) {
        
        lowLink[node] = dfn[node] = timer++;
        
        for(auto child: adj[node]) {
            if(!dfn[child]) {
                tarjan(child, node, adj);
                lowLink[node] = min(lowLink[node], lowLink[child]);
            }else if(child != par) {
                lowLink[node] = min(lowLink[node], dfn[child]);
            }
        }
        
        if(lowLink[node] == dfn[node] and ~par) {
            bridges.push_back({par, node}); // critical bridge
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        timer = 1;
        bridges.clear();
        
        lowLink = dfn = vector<int> (n);
        vector<vector<int>> adj(n);
    
        for(int i = 0; i < size(connections); i++) {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        tarjan(0, -1, adj);
        
        return bridges;
    }
};