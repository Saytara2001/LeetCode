class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));
        int ans = 0;
        int mnEnd = intervals[0][1];
        for(int i = 1 ; i < size(intervals); i++) {
            //second start less than first end
            if(intervals[i][0] < mnEnd) {
                //look at whose has minimun end
                mnEnd = min(mnEnd, intervals[i][1]);
                ans++;
            }else
                mnEnd = intervals[i][1];
        }
        return ans;
    }
};