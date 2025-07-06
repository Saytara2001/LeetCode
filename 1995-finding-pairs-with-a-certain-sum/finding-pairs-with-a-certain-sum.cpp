class FindSumPairs {
public:
    vector<int> v, nums;
    unordered_map<int, int> freq;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        v = nums1;
        nums = nums2;
        for(auto x: nums2)
            ++freq[x];
    }
    
    void add(int index, int val) {
        --freq[nums[index]];
        nums[index] += val;
        ++freq[nums[index]];
    }
    
    int count(int tot) {
        int pairs = 0;
        for(int i = 0; i < v.size(); i++) {
            int need = tot - v[i];
            if(freq.count(need))
                pairs += freq[need];
        }
        return pairs;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */