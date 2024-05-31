class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        set<int> st;
        for(auto it: nums) {
            if(st.find(it) != end(st)) {
                st.erase(it);
            }else {
                st.insert(it);
            }
        }
        vector<int> res{*st.begin(), *st.rbegin()};
        return res;
    }
};