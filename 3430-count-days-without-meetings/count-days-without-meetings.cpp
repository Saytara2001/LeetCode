class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = size(meetings);
        sort(begin(meetings), end(meetings));
        int lstEnd = 0, freeDays = 0;
        for(int i = 0; i < n; i++) {
            int st = meetings[i][0], end = meetings[i][1];
            if(st > lstEnd) {
                freeDays += st - lstEnd - 1;
            } 
            lstEnd = max(lstEnd, end);
        }
        freeDays += days - lstEnd;
        return freeDays;
    }
};