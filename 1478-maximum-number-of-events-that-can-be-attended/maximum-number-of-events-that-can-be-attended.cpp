class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int day = 1, cnt = 0;
        sort(begin(events), end(events));
        priority_queue<int> pq;
        int maxDay = 0;
        for(int i = 0; i < size(events); i++) {
            maxDay = max(maxDay, events[i][1]);
        }
        for(int i = 1, j = 0; i <= maxDay; i++) {
            while(j < size(events) and events[j][0] <= i) {
                pq.push(-events[j][1]);
                ++j;
            }
            if(pq.size() and -pq.top() >= i) {
                ++cnt;
                pq.pop();
            }
            while(pq.size() and -pq.top() <= i) 
                pq.pop(); // remove useless
        }
        return cnt;
    }
};