class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> freq(size(nums) + 1);
        for(auto it : nums) {
            if(freq[it] >= res.size()) 
                res.push_back({});
            res[freq[it]].push_back(it);
            freq[it]++;
        }
        return res;
    }
};