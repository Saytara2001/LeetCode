class Solution {
public:
    bool checkRow(int r, int x, vector<vector<char> > &board) {
        for (int c = 0; c < 9; c++) {
            if (board[r][c] - '0' == x)
                return false;
        }
        return true;
    }

    bool checkColumn(int c, int x, vector<vector<char> > &board) {
        for (int r = 0; r < 9; r++) {
            if (board[r][c] - '0' == x)
                return false;
        }
        return true;
    }

    bool check3x3(int r, int c, int x, vector<vector<char> > &board) {
        r = 3 * (r / 3);
        c = 3 * (c / 3);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; ++j) {
                if (board[r + i][c + j] - '0' == x)
                    return false;
            }
        }
        return true;
    }

    bool solve(int i, int j, vector<vector<char> > &board) {
        if (i == 9 and j == 0) {
            return true;
        }
        if (board[i][j] == '.') {
            for (int x = 1; x <= 9; ++x) {
                if (check3x3(i, j, x, board) and checkRow(i, x, board) and checkColumn(j, x, board)) {
                    board[i][j] = char(x + '0');
                    if (solve(j == 8 ? i + 1 : i, (j + 1) % 9, board))
                        return true;
                    board[i][j] = '.';
                }
            }
        } else {
            return solve((j == 8 ? i + 1 : i), (j + 1) % 9, board);
        }
        return false;
    }

    void solveSudoku(vector<vector<char> > &board) {
        solve(0, 0, board);
    }
};