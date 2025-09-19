class Spreadsheet {
public:
    vector<vector<int>> grid;
    Spreadsheet(int rows) {
        grid = vector<vector<int>> (rows + 1, vector<int> (27)); // zero-based
    }
    
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1));
        grid[row][col] = value;
    }
    
    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1));
        grid[row][col] = 0;
    }
    int get(string s) {
        if(s[0] >= 'A' and s[0] <= 'Z') {
            int x = stoi(s.substr(1));
            int y = s[0] - 'A';
            return grid[x][y];
        } 
        return stoi(s);
    }
    int getValue(string formula) {
        int plus = formula.find('+');
        string a = formula.substr(1, plus - 1);
        string b = formula.substr(plus + 1);
        return get(a) + get(b);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */