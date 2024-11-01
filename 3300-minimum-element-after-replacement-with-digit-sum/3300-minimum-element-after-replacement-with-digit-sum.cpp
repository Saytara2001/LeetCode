class Solution {
public:
    int minElement(vector<int>& nums) {
        int mn = 1e5;
        for(auto& num: nums) {
            int sum = 0;
            int x = num;
            while(x) {
                sum += x % 10;
                x /= 10;
            }
            mn = min(mn, sum);
        }
        
        return mn;
    }
};