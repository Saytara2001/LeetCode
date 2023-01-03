class Solution {
public:
    int head[20], nxt[100], to[100], ne, n;
    void init(){
        memset(head, -1, sizeof head);
        ne = 0;
    }
    void addEdge(int f, int t){
        to[ne] = t;
        nxt[ne] = head[f];
        head[f] = ne++;
    }
    vector<vector<int>> all_paths;
    void dfs(int node, vector<int> path, vector<vector<int>> graph){
        path.push_back(node);
        if(node == graph.size()-1){
            all_paths.push_back(path);
            return;
        }
        for(int e = head[node]; ~e ; e = nxt[e]){
            int v = to[e];
            dfs(v, path, graph);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        init();
        int node = 0;
        for(auto v1:graph){
            for(auto v2:v1){
                addEdge(node, v2);
            }
            node++;
        }
        vector<int> path;
        dfs(0, path, graph);
        return all_paths;
    }
};