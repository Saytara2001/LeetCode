class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        multiset<int> st1, st2;
        int l = 0, r = size(costs) - 1;
        long long ans = 0;
        while(k--) {
            while (l <= r) {
                if(size(st1) < candidates) {
                    st1.insert(costs[l++]);
                }else if(size(st2) < candidates) {
                    st2.insert(costs[r--]);
                }else
                    break;
            }
            if(st2.empty() or (!st1.empty() and *st1.begin() <= *st2.begin())) {
                ans += *st1.begin();
                st1.erase(st1.begin());
            }
            else {
                ans += *st2.begin();
                st2.erase(st2.begin());
            }
        }
        return ans;
    }
};