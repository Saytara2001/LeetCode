class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> freq(value);
        for(auto x: nums) {
            int val = (x % value + value) % value;
            ++freq[val];
        }
        int mn = 0;
        for(int i = 0; i < value; i++) {
            if(freq[mn] > freq[i]) mn = i;
        }
        int mex = max(0, freq[mn]) * value + mn;
        return mex;
    }
};