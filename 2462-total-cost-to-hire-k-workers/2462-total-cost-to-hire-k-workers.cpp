class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>,greater<int>> q1, q2;
        int l = 0, r = size(costs) - 1;
        long long ans = 0;
        while(k--) {
            while (l <= r) {
                if(size(q1) < candidates) {
                    q1.push(costs[l++]);
                }else if(size(q2) < candidates) {
                    q2.push(costs[r--]);
                }else
                    break;
            }
            if(q2.empty() or (!q1.empty() and q1.top() <= q2.top())) {
                ans += q1.top();
                q1.pop();
            }
            else {
                ans += q2.top();
                q2.pop();
            }
        }
        return ans;
    }
};