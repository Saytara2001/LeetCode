class Solution {
public:
    bool checkColumn(int r, vector<vector<char> > &board) {
        vector<int> vis(10);
        for (int c = 0; c < 9; c++) {
            if (board[r][c] == '.') continue;
            if (vis[board[r][c] - '0']) return false;
            vis[board[r][c] - '0'] = true;
        }
        return true;
    }

    bool checkRow(int c, vector<vector<char> > &board) {
        vector<int> vis(10);
        for (int r = 0; r < 9; r++) {
            if (board[r][c] == '.') continue;
            if (vis[board[r][c] - '0']) return false;
            vis[board[r][c] - '0'] = true;
        }
        return true;
    }

    bool check3x3(int r, int c, vector<vector<char> > &board) {
        vector<int> vis(10);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; ++j) {
                if (board[r + i][c + j] == '.') continue;
                if (vis[board[r + i][c + j] - '0']) return false;
                vis[board[r + i][c + j] - '0'] = true;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char> > &board) {
        //1. check each row and col
        for (int i = 0; i < 9; ++i) {
            if (!checkColumn(i, board) or !checkRow(i, board))
                return false;
        }
        vector<int> v {0,3,6};
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (!check3x3(v[i], v[j], board)) return false;
            }
        }
        return true;
    }
};