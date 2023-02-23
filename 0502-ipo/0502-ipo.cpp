class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = capital.size();
        
        vector<pair<int ,int>> vp(n);
        for(int i = 0; i < n; i++) {
            vp[i].first = capital[i];
            vp[i].second = profits[i];
        }
        sort(vp.begin(), vp.end());
        
        int i = 0;
        priority_queue<int> pq;
        while(k--) {
            while(i < n and w >= vp[i].first) {
                pq.push(vp[i].second);
                i++;
            }
            if(pq.size()) {
                w += pq.top();
                pq.pop();
            }
        }
        return w;
    }
};