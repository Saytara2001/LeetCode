class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        
        int n = size(nums), Mn = 1e9;
        
        long long sum = 0;
        deque<pair<long long, int>> dq; // sum, index
        
        
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            
            // This handles to remove sum equal = 0
            if(sum >= k)
                Mn = min(Mn, i + 1);
            
            // make the dq monotonic increasing
            while(dq.size() and sum <= dq.back().first) {
                dq.pop_back();
            }
            
            while(dq.size() and sum - dq.front().first >= k) {
                Mn = min(Mn, i - dq.front().second);
                dq.pop_front();
            }
            
            dq.push_back({sum, i});
        }
        
        return Mn == 1e9 ? -1 : Mn;
    }
};