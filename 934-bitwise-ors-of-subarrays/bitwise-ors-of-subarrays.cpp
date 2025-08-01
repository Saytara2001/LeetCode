class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int> prev, ans;
        // Time complexity is : 32 * n
        for(auto x: arr) {

            set<int> next;
            next.insert(x);

            for(auto p: prev) {
                next.insert(p | x);
            }

            prev = next;
            for(auto it: next)
                ans.insert(it);
        }
        return ans.size();

        return ans.size();
    }
};