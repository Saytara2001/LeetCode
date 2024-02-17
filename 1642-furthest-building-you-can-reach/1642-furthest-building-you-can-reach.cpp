class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        multiset<int> biggest;
        long long rem = 0; 
        int n = size(heights);
        for(int i = 1; i < n; i++) {
            int diff = heights[i] - heights[i - 1];
            if(diff > 0) {
                if(ladders > 0) {
                    biggest.insert(diff);
                    ladders--;
                }else {
                    if(biggest.size() and *biggest.begin() < diff) {
                        rem += *biggest.begin();
                        biggest.erase(biggest.begin());
                        biggest.insert(diff);
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