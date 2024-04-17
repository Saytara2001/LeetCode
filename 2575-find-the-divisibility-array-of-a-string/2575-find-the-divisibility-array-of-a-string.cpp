class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        long long sum = 0;
        vector<int> res;
        for(auto c: word) {
            sum = (sum * 10 + (c - '0')) % m;
            res.push_back(sum == 0);
        }
        return res;
    }
};