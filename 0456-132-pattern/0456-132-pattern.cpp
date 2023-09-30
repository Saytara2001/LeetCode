class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        multiset<int> ms;
        
        for(int i = 1; i < n; i++)
            ms.insert(nums[i]);
        
        int preMn = nums.front();
        for(int i = 1; i < n; i++) {
            
            auto it = ms.upper_bound(preMn);
            
            if(nums[i] > preMn and it != end(ms) and nums[i] > *it)
                return true;
            
            auto it2 = ms.find(nums[i]);
            if(it2 != end(ms))
                ms.erase(it2);
            
            preMn = min(preMn, nums[i]);
        }
        return false;
    }
};