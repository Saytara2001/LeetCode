class Solution {
public:
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> in(n);
        for(auto it: edges) {
            in[it[1]]++;
            adj[it[0]].push_back(it[1]);
        }
        vector<set<int>> res(n);
        
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(!in[i]) {
                q.push(i);
            }
        }
        //bfs topological sort
        while(q.size()) {
            int node = q.front();
            q.pop();
            
            for(auto child: adj[node]) {
                for(auto it: res[node]) {
                    res[child].insert(it);
                }
                res[child].insert(node);
                if(--in[child] == 0) {
                    q.push(child);
                }
            }
        }
        vector<vector<int>> ans(n);
        for(int i = 0; i < n; i++) {
            ans[i].assign(begin(res[i]), end(res[i]));
        }
        return ans;
    }
};