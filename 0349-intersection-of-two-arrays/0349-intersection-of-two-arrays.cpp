class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<bool> freq(1001);
        for(auto it: nums1) {
            freq[it] = true;
        }
        vector<int> res;
        for(auto it: nums2) {
            if(freq[it]) {
                res.push_back(it);
                freq[it] = false;
            }
        }
        return res;
    }
};