class Solution {
public:
    bool valid(int i, int j, int n, int m) {
        return i >= 0 and i < n and  j >= 0 and j < m;
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = size(land), m = size(land[0]);
        vector<vector<bool>> vis(n, vector<bool> (m));
        vector<vector<int>> res;
            
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] and land[i][j]) {
                    vector<int> rec {i, j};
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    int fi = i, fj = j;
                    while(q.size()) {
                        
                        auto [x, y] = q.front();
                        q.pop();
                        
                        if(valid(x + 1, y, n, m) and !vis[x + 1][y] and land[x + 1][y]) {
                            q.push({x + 1, y});
                            vis[x + 1][y] = true;
                            fi = x + 1;
                            fj = y;
                        }
                        if(valid(x, y + 1, n, m) and !vis[x][y + 1] and land[x][y + 1]) {
                            q.push({x, y + 1});
                            vis[x][y + 1] = true;
                            fi = x;
                            fj = y + 1;
                        }
                    }
                    rec.push_back(fi); 
                    rec.push_back(fj);
                    res.push_back(rec);
                }
            }
        }
        return res;
    }
};