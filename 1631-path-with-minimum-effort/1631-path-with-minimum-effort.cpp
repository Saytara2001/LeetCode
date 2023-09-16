class Solution {
public:
    int dx[4] = {-1, 0 , 1, 0},
        dy[4] = {0, 1 , 0, -1};
    bool valid(int i, int j, int n, int m) {
        return (i >= 0 and i < n and j >= 0 and j < m);
    }
    bool can(int diff, vector<vector<int>>& v) {
        
        queue<pair<int, int>> q;
        int n = v.size();
        int m = v[0].size();
        vector<vector<int>> vis(n, vector<int> (m));
        
        q.push({0 ,0});
        vis[0][0]= 1;
        
        
        while(q.size()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            for(int d = 0; d < 4 ; d++) {
                int ni = i + dx[d]; 
                int nj = j + dy[d];
                if(valid(ni, nj, n, m) and !vis[ni][nj] and abs(v[ni][nj] - v[i][j]) <= diff) {
                    q.push({ni, nj});
                    vis[ni][nj] = 1;
                }
            }
        }
        return vis[n - 1][m - 1];
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int l = 0, r = 1e6;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(can(mid, heights)) {
                r = mid;
            }else {
                l = mid + 1;
            }
        }
        return r;
    }
};