class Solution {
public:
    int n, m;
    int dx[4] = {1, -1, 0,  0};       
    int dy[4] = {0,  0, 1, -1,};
    vector<vector<bool>> vis;
    bool rec(int i, int j, int idx, string s, vector<vector<char>>& board, string& word) {
        if(idx == size(word)) 
            return true;
        if(i < 0 or i >= n or j < 0 or j >= m or vis[i][j]) 
            return false;
        
        for(int d = 0; d < 4; d++) {
            int ni = i + dx[d];
            int nj = j + dy[d];
            if(word[idx] == board[i][j]) {
                vis[i][j] = true;
                if(rec(ni, nj, idx + 1, s + board[i][j], board, word)) 
                    return true;
            }
        }
        vis[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = size(board), m = size(board[0]);
        vis = vector<vector<bool>> (n, vector<bool> (m));
        //Time: n * m * dfs ==> n * m * (4 ^ size(word))
        for(int i = 0; i < n; i++) {
            for(int j = 0;  j < m; j++) {
                if(rec(i, j, 0, "", board, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};