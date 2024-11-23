class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        
        int n = size(nums), Mn = 1e9;
        
        long long sum = 0;
        // sum, index
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq; 
        
        
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            
            // This handles to remove sum equal = 0
            if(sum >= k)
                Mn = min(Mn, i + 1);
            
            while(pq.size() and sum - pq.top().first >= k) {
                Mn = min(Mn, i - pq.top().second);
                pq.pop();
            }
            
            pq.push({sum, i});
        }
        
        return Mn == 1e9 ? -1 : Mn;
    }
};