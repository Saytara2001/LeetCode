class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int, multiset<int>> sums;
        auto getSum = [&](int x) {
            int sum = 0;
            while(x > 0) {
                sum += x % 10;
                x /= 10;
            }
            return sum;
        };
        for(auto num: nums) {
            int s = getSum(num);
            sums[s].insert(num);
            if(sums[s].size() > 2) {
                sums[s].erase(sums[s].begin());
            }
        }
        int mx = -1;
        for(auto [s, st]: sums) {
            if(st.size() == 2) {
                mx = max(mx, *st.begin() + *st.rbegin());
            }
        }
        return mx;
    }
};