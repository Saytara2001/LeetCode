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
            int cost1 = q1.size() > 0? q1.top() : INT_MAX;
            int cost2 = q2.size() > 0? q2.top() : INT_MAX;
            if(cost1 <= cost2) {
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