class Solution {
public:
    set<vector<int>> set;
    vector<int> v;
    void rec(int i, vector<int>& nums) {
        if(i == nums.size()){
            if(v.size() > 1 and !set.count(v)){
                set.insert(v);
            }
            return;
        }
        //take
        if(v.empty() or v.back() <= nums[i]){
            v.push_back(nums[i]);
            rec(i+1, nums);
            v.pop_back();
        }
        //leave
        rec(i+1, nums);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        rec(0, nums);
        return vector(set.begin(), set.end());
    }
};