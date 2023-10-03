class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        int freq[101] = {0};
        int ans = 0;
        
        for(auto it: nums) {
            ans += freq[it]++;
        }
        
        return ans;
    }
};