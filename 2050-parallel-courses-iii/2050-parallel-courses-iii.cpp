class Solution {
public:
    vector<int> in;
    vector<vector<int>> adj;
    int bfs(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<bool> vis(n + 1);
        vector<int> cost(n + 1);
        queue<int> q;
        int maxTime = 0;
        for(int i = 1; i <= n; i++) {
            if(!in[i]) {
                q.push(i);
                vis[i] = 1;
            }
            cost[i] = time[i - 1];
            maxTime = max(maxTime, time[i - 1]);
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for(auto child: adj[node]) {
                if(in[child] > 0) {
                    if(--in[child] == 0) {
                        q.push(child);
                        vis[child] = 1;
                    }
                    cost[child] = max(cost[node] + time[child - 1], cost[child]);
                }
            }
        }
        return max(maxTime, *max_element(begin(cost), end(cost)));
    }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        in = vector<int> (n + 1);
        adj = vector<vector<int>> (n + 1);
        for(auto it: relations) {
            in[it[1]]++;
            adj[it[0]].push_back(it[1]);
        }
        return bfs(n, relations, time);
    }
};