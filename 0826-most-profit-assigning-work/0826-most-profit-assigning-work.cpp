class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        multiset<int> ms;
        vector<pair<int, int>> vp;
        int n = size(profit);
        
        for(int i=  0; i < n; i++) {
            vp.push_back({difficulty[i], profit[i]});
        }
        
        sort(begin(vp), end(vp));
        sort(begin(worker), end(worker));
        
        int res = 0;
        int j = 0;
        for(int i = 0; i < size(worker); i++) {
            while(j < n and vp[j].first <= worker[i]) {
                ms.insert(vp[j].second);
                j++;
            }
            if(ms.size())
                res += *ms.rbegin();
        }
        
        return res;
    }
};