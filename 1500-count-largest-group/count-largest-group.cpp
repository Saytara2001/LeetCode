class Solution {
public:
    int countLargestGroup(int n) {
        int maxGroup = 0;
        vector<int> freq(38);
        for(int i = 1; i <= n; i++) {
            int x =  i, sum = 0;
            while(x > 0) {
                sum += x % 10;
                x /= 10;
            }
            maxGroup = max(maxGroup, ++freq[sum]);
        }
        int cntMaxGroups = 0;
        for(auto it: freq) {
            cntMaxGroups += it == maxGroup;
        }
        return cntMaxGroups;
    }
};