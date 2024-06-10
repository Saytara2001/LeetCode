class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> v = heights;
        sort(begin(v), end(v));
        int n = size(heights), cnt = 0;
        for(int i = 0; i < n; i++) {
            cnt += v[i] != heights[i];
        }
        return cnt;
    }
};