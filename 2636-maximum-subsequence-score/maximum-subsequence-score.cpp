class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++) v[i].first = nums1[i];
        for(int i = 0; i < n; i++) v[i].second = nums2[i];
        sort(begin(v), end(v), [&](auto& a, auto& b) {
            return a.second > b.second;
        });
        
        priority_queue<int, vector<int>, greater<>> pq;
        long long res = 0, sum = 0;
        for(int i = 0; i < k; i++) {
            pq.push(v[i].first);
            sum += v[i].first;
        }
        res = max(res, 1LL * sum * v[k - 1].second);
        for(int i = k; i < n; i++) {
            if(pq.top() < v[i].first) {
                sum -= pq.top();
                pq.pop();

                sum += v[i].first;
                pq.push(v[i].first);
            }
            res = max(res, 1LL * sum * v[i].second);
        }
        return res;
    }
};