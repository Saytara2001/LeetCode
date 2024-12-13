class Solution {
public:
    long long findScore(vector<int>& nums) {
        
        int n = size(nums);
        vector<pair<int, int>> vp;
        
        for(int i = 0; i < n; i++) {
            vp.push_back({nums[i], i});
        }
        
        sort(begin(vp), end(vp));
        
        long long sum = 0;
        vector<bool> vis(n);
        for(int i = 0; i < n; i++) {
            int index = vp[i].second;
            if(!vis[index]) {
                sum += vp[i].first; 
                vis[index] = vis[max(index - 1, 0)] = vis[min(index + 1, n - 1)] = 1;
            }
        }
        
        return sum;
    }
};