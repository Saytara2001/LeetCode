class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        
        sort(begin(queries), end(queries));
        
        long long sum = 0;
        int p = 0, take = 0;
        int n = size(nums), q = size(queries);
        
        priority_queue<int> pq;         
        vector<int> pref(n + 2);
        
        for(int i = 0; i < n; i++) {
            sum -= pref[i];
            
            while(p < q and queries[p][0] <= i) {
                pq.push(queries[p++][1]);
            }
            
            while(nums[i] - sum > 0 and pq.size()) {
                
                int t = pq.top();
                pq.pop();
                
                if(t >= i) {
                    ++sum;
                    ++take;
                    ++pref[t + 1];
                }
            }
            if(nums[i] - sum > 0) 
                return -1;
        }
        
        return q - take;
    }
};