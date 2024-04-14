class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int idx = max_element(begin(nums), end(nums)) - begin(nums);
        map<int, int> mp;
        int n = size(nums);
        int sz = n;
        vector<int> res(sz, -1);
        stack<int> st;
        while(n--) {
            while(st.size() and nums[idx] >= st.top()) st.pop();
            if(st.size()) {
                res[idx] = st.top();
            }else {
                res[idx] = -1;
            }
            st.push(nums[idx]);
            idx = ((idx - 1) + sz) % sz;
        }
        return res;
    }
};