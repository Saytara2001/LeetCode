class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int cust = 0;
        int n = size(customers);
        for(int i = 0; i < n; i++) {
            if(grumpy[i] == 0) {
                cust += customers[i];
                customers[i] = 0;
            } 
            if(i > 0) {
                customers[i] += customers[i - 1];
            }
        }
        int mx = cust;
        for(int i = 0; i + minutes <= n; i++) {
            int pref = 0;
            if(i == 0) pref = customers[i + minutes - 1];
            else pref = customers[i + minutes - 1] - customers[i - 1];
            mx = max(mx, cust + pref);
        }
        return mx;
    }
};