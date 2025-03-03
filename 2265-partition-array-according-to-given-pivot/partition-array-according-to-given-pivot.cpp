class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        int cnt = 0;
        vector<int> res, rem;

        for(auto x: nums) {
            if(x == pivot) ++cnt;
            if(x > pivot) rem.push_back(x);
            if(x < pivot) res.push_back(x);
        }

        while(cnt--)
            res.push_back(pivot);

        for(auto x: rem)
            res.push_back(x);

        return res;
    }
};