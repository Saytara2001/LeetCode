class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> even, odd;
        for(auto it: nums) {
            it & 1 ? odd.push_back(it) : even.push_back(it);
        }
        for(auto it: odd)
            even.push_back(it);
        return even;
    }
};