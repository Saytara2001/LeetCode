class Graph {
public:
    int sz;
    vector<vector<pair<int, int>>> adj;
    Graph(int n, vector<vector<int>>& edges) {
        sz = n;
        adj = vector<vector<pair<int, int>>> (n);
        for(int i = 0; i < size(edges); i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        
        vector<int> dist(sz, 1e9);
        queue<int> q;
        
        q.push(node1);
        dist[node1] = 0;
        
        while(q.size()) {
            
            int node = q.front();
            q.pop();
            
            for(auto it: adj[node]) {
                
                int child = it.first;
                int cost = it.second;
                
                if(dist[child] > dist[node] + cost) {
                    dist[child] = dist[node] + cost;
                    q.push(child);
                }
            }
        }
        
        return dist[node2] == 1e9 ? -1 : dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */