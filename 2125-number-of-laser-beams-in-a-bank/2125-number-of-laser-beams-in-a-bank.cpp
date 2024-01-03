class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int numberOfLeasers = 0;
        int preRow = 0;
        for(int i = 0; i < size(bank); i++) {
            int CurRow = 0;
            for(int j = 0; j < size(bank[i]); j++) {
                CurRow += (bank[i][j] == '1');
            }
            numberOfLeasers += preRow * CurRow;
            if(CurRow != 0)
                preRow = CurRow;
        }
        return numberOfLeasers;
    }
};