class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;
        for(auto num: nums) {
            num > 0 ? pos.push_back(num) : neg.push_back(num);
        }
        vector<int> res;
        for(int i = 0; i < size(pos); i++) {
            res.push_back(pos[i]); 
            res.push_back(neg[i]);
        }
        return res;
    }
};