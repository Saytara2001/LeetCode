class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        
        auto it = lower_bound(begin(nums), end(nums), target);
        if(it != end(nums) and *it == target)
            res.push_back(it - begin(nums));
        else
            res.push_back(-1);
        
        it = upper_bound(begin(nums), end(nums), target);
        if(it != begin(nums) and *(--it) == target)
            res.push_back(it - begin(nums));
        else
            res.push_back(-1);
        
        return res;
    }
};