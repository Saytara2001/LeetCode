class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        pq.push({nums[0], 0});
        int mx = nums[0];
        
        for(int i = 1; i < size(nums); i++) {
            while(i - pq.top().second > k) {
                pq.pop();
            }
            
            int cur = max(0, pq.top().first) + nums[i];
            mx = max(mx, cur);
            pq.push({cur, i});
        }
        return mx;
    }
};