class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int cnt = 0;
        vector<vector<int>> freq(10, vector<int> (10));
        for(auto dom : dominoes) {
            cnt += freq[dom[0]][dom[1]];
            if(dom[0] != dom[1])
                cnt += freq[dom[1]][dom[0]];
            ++freq[dom[0]][dom[1]];
        }
        return cnt;
    }
};