class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> ans;
        int n = rocks.size();
        for(int i = 0; i < n; i++){
            ans.push_back(capacity[i] - rocks[i]);
        }
        sort(ans.begin(), ans.end());
        int maxBags = n - ans.size();
        for(int i = 0; i < (int)ans.size(); i++) {
            if(ans[i] <= additionalRocks)
                additionalRocks -= ans[i], maxBags++;
            else 
                break;
        }
        return maxBags;
    }
};