class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // O(n)
        int candidate = 0, count = 0;
        for(auto it: nums) {
            if(it == candidate) {
                count++;
            }else if(count > 0) {
                count--;
            }else {
                candidate = it;
            }
        }
        return candidate;
    }
};