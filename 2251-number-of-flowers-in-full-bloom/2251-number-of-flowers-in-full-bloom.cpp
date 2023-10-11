class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        
        vector<int> start, finish;
        for(auto it: flowers) {
            start.push_back(it[0]);
            finish.push_back(it[1] + 1);
        }
        
        sort(begin(start), end(start));  
        sort(begin(finish), end(finish));
        
        vector<int> res;
        for(auto it: people) {
            int j = upper_bound(begin(start), end(start), it) - begin(start);
            int i = upper_bound(begin(finish), end(finish), it) - begin(finish);
            res.push_back(j - i);
        }
        return res;
    }
};