class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back({100001,100001}); // dummey
        
        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i][0] > newInterval[0]){
                intervals.insert(intervals.begin() + i, newInterval);
                break;
            }
        }
        
        vector<vector<int>> result;
        newInterval = intervals[0];
        for(int i = 0; i < intervals.size(); i++){
            if(newInterval[1] >= intervals[i][0]){
                newInterval[1] = max(newInterval[1],intervals[i][1]);
            }else{
                result.push_back(newInterval);
                newInterval = intervals[i];
            }
        }
        return result;
    }
};