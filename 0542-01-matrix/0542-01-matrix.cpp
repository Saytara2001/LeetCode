class Solution {
public:
    int dx[4] = {0, 1, -1, 0},
        dy[4] = {1, 0, 0, -1};
    queue<pair<int, int>> q;
    map<pair<int, int>, bool> vis;
    void bfs(vector<vector<int>>& mat, vector<vector<int>>& ans) {
        
        int dis = 0;
        while(!q.empty()) {
            dis++;
            int sz = q.size();
            while(sz--) {
                auto par = q.front();
                q.pop();

                for(int d = 0; d < 4; d++) {
                    int ni = par.first + dx[d];
                    int nj = par.second + dy[d];
                    if(ni < 0 or nj < 0 or ni >= mat.size() or nj >= mat[0].size())
                        continue;
                    if(!vis[{ni, nj}]) {
                        ans[ni][nj] = dis;
                        q.push({ni, nj});
                        vis[{ni, nj}] = 1;
                    }
                }
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        vector<vector<int>> ans(mat.size(), vector<int> (mat[0].size()));
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[i].size(); j++) {
                if(mat[i][j] == 0) {
                    q.push({i, j});
                    vis[{i, j}] = 1;
                }
            }
        }
        
        bfs(mat, ans);
        
        return ans;
    }
};