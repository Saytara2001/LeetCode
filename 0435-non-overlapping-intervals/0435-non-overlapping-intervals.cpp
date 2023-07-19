class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));
        int ans = 0;
        int lst_interval = 0;
        for(int i = 1 ; i < size(intervals); i++) {
            //second start less than first end
            if(intervals[i][0] < intervals[lst_interval][1]) {
                //look at whose has minimun end
                if(intervals[i][1] < intervals[lst_interval][1]) {
                    lst_interval = i;
                }
                ans++;
            }else
                lst_interval = i;
        }
        return ans;
    }
};