class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(begin(nums), end(nums), [&](auto &x, auto &y){
           return x % 2 < y % 2; 
        });
        return nums;
    }
};