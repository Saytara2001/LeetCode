class Solution {
public:
    set<string> vis;
    string res = "?";
    void rec(int i, int n, string s) {
        if(i == n) {
            if(!vis.count(s))
                res = s;
            return;
        }
        rec(i + 1, n, s + "0");
        if(res != "?") return;
        
        rec(i + 1, n, s + "1");
        if(res != "?") return;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = size(nums);
        for(auto it: nums) {
            vis.insert(it);
        }
        rec(0, n, "");
        return res;
    }
};