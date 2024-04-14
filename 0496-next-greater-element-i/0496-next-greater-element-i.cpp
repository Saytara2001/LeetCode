class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nxt(10001);
        int n = size(nums2);
        stack<int> st;
        for(int i = n - 1; i >= 0 ; i--) {
            while(st.size() and nums2[i] > st.top()) st.pop();
            if(st.size()) {
                nxt[nums2[i]] = st.top();
            }else {
                nxt[nums2[i]] = -1;
            }
            st.push(nums2[i]);
        }
        vector<int> res;
        for(auto it: nums1) {
            res.push_back(nxt[it]);
        }
        return res;
    }
};