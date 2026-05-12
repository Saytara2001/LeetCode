class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int minSum = 0;
        vector<array<int, 3>> all;
        for(auto task: tasks) {
            minSum += task[0];
            all.push_back({task[1] - task[0], task[1], task[0]});
        }
        int res = minSum;
        sort(all.begin(), all.end(), [&](auto& x, auto & y) {
            if(x[0] != y[0]) 
                return x[0] > y[0];
            return x[1] > y[1];
        });
        for(auto cur: all) {
            if(minSum < cur[1]) {
                res += cur[1] - minSum;
                minSum += cur[1] - minSum;
            } 
            minSum -= cur[2];
        }
        return res;
    }
};