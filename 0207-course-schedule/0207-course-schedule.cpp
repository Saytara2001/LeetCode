class Solution {
public:
    vector<vector<int>> adj;
    vector<int> in;
    bool bfs(int n) {
        queue<int> q;
        
        for(int i = 0; i < n; i++)
            if(!in[i])
                q.push(i);
        
        while(!q.empty()) {
            
            int node = q.front();
            q.pop();
            
            for(auto child: adj[node]) {
                if(in[child] > 0) {
                    in[child]--;
                    if(in[child] == 0)
                        q.push(child);
                }
            }
        }
        
        return count(begin(in), end(in), 0) == n;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        adj = vector<vector<int>> (numCourses);
        in = vector<int> (numCourses, 0);
        
        for(int i = 0; i < size(prerequisites); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            in[prerequisites[i][0]]++;
        }
        
        return bfs(numCourses);
    }
};