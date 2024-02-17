class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        multiset<int> ms;
        long long rem = 0; 
        int n = size(heights);
        for(int i = 1; i < n; i++) {
            int diff = heights[i] - heights[i - 1];
            if(diff > 0) {
                if(ladders > 0) {
                    ms.insert(diff);
                    ladders--;
                }else {
                    if(ms.size() and *ms.begin() < diff) {
                        rem += *ms.begin();
                        ms.erase(ms.begin());
                        ms.insert(diff);
                    }else {
                        rem += diff;
                    }
                    if(rem > bricks)
                        return i - 1;
                }
            }
        }
        return n - 1;
    }
};