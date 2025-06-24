class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ind;
        for(int i = 0; i < size(nums); i++) {
            if(nums[i] == key) {
                ind.push_back(i);
            }
        }
        vector<int> res;
        for(int i = 0; i < size(nums); i++) {
            auto it = lower_bound(begin(ind), end(ind), i);
            if(it != end(ind) and *it - i <= k) 
                res.push_back(i);
            else if(it != begin(ind)) {
                --it;
                if(i - *it <= k)
                    res.push_back(i);
            }
        }
        return res;
    }
};