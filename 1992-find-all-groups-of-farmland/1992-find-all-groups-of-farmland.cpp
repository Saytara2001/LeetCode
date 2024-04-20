class Solution {
public:
    bool valid(int i, int j, int n, int m) {
        return i >= 0 and i < n and  j >= 0 and j < m;
    }
    int dx[2] = {1, 0},
        dy[2] = {0, 1};
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = size(land), m = size(land[0]);
        vector<vector<int>> res;
            
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(land[i][j]) {
                    vector<int> rec {i, j};
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    int fi = i, fj = j;
                    while(q.size()) {
                        
                        auto [x, y] = q.front();
                        q.pop();
                        
                        for(int d = 0; d < 2 ; d++) {
                            int ni = x + dx[d];
                            int nj = y + dy[d];
                            if(valid(ni, nj, n, m) and land[ni][nj]) {
                                q.push({ni, nj});
                                land[ni][nj] = 0;
                                fi = ni;
                                fj = nj;
                            }
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