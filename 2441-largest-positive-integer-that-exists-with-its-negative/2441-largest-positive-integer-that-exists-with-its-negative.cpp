class Solution {
public:
    int findMaxK(vector<int>& nums) {
        vector<bool> vis(1000);
        for(auto it: nums) {
            if(it > 0) vis[it] = true;
        }
        int mx = -1;
        for(auto it: nums) {
            if(it < 0 and vis[-it]) {
                mx = max(mx, -it);
            }
        }
        return mx;
    }
};