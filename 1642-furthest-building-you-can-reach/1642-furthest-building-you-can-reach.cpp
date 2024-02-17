class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        long long rem = 0; 
        int n = size(heights);
        for(int i = 1; i < n; i++) {
            int diff = heights[i] - heights[i - 1];
            if(diff > 0) {
                if(ladders > 0) {
                    pq.push(-diff);
                    ladders--;
                }else {
                    if(pq.size() and -pq.top() < diff) {
                        rem += -pq.top();
                        pq.pop();
                        pq.push(-diff);
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